#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::chrono::high_resolution_clock;
using std::rand;
using std::srand;
using std::time;
using std::chrono::duration_cast;
using std::chrono::microseconds;
//
/*
Write a program to solve the selection problem. The selection problem determines the largest
element from a set of N numbers. It can be solved using the following steps:
1. Initialize an array of size N with elements
2. Apply bubble sort in descending order to the elements
3. Return the Kth element from the array
*/

void bubbleSort(int A[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] < A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(0));
    int N = 100;

    // 100 -> 43ms
    // 1000 -> 2369 ms
    // 10000 -> 274285 ms
    // 100000 -> 30960774 ms
    // 1000000 -> N/A

    int array[N] = {};
    for(int i = 0; i<N; i++){
        array[i] = rand();
    }

    auto start = high_resolution_clock::now();
    bubbleSort(array, N);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << "ms" << endl;

    return 0;
}