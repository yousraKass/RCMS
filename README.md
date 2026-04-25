# Restaurant Chain Management System (RCMS)

A C++ application demonstrating advanced data structures and algorithms for managing a multi-level restaurant chain across different geographical regions in Algeria.

---

## Project Overview

This project implements a **Restaurant Chain Management System** that efficiently handles:
- **Hierarchical geographic organization** (Country → Wilaya/Province → District → City)
- **Advanced data structures** for optimal search and insert performance
- **Restaurant management** with sales, costs, ratings, and prize winner tracking
- **Performance analysis** comparing AVL Trees vs Binary Search Trees

The system is designed to manage thousands of restaurants across Algeria with emphasis on **performance optimization** and **scalability**.

---

## Key Features

### 1. **Restaurant Management**
- Complete restaurant profile management across 48 Algerian Wilayas (provinces)
- Support for 5 different cuisine types per restaurant (Algerian, Syrian, Chinese, European, Indian)
- Daily sales tracking distributed across cuisines
- Daily cost tracking (rent, employees, utilities, ingredients, publicity)
- Sales-to-publicity ratio calculation

### 2. **Geographic Management**
- Multi-level hierarchical structure: Country → Wilaya → District → City
- Efficient location-based restaurant organization
- Aggregate reporting at any geographic level (country, wilaya, district, city)

### 3. **Advanced Data Structures**
- **AVL Trees** for self-balancing search with O(log n) operations
- **Binary Search Trees** for comparison and performance analysis
- Both implementations with insert, search, and traversal operations

### 4. **Performance Analytics**
- **Rating System**: Monthly cuisine ratings based on customer feedback
- **Prize Winners**: Automatic identification of best-performing restaurants monthly
  - Prize calculation: `Amount = Monthly_Sales + (Rating/100)`
  - Cumulative monthly tracking
- **Sales Analysis**: Monthly reports for any geographic level
- **Performance Comparison**: AVL vs BST runtime analysis

---

## Architecture

### Directory Structure
```
RCMS/
├── src/                          # Source files (.cpp)
│   ├── main.cpp                 # Entry point
│   ├── Restaurant.cpp           # Restaurant management
│   ├── AVLRestaurant.cpp        # AVL tree implementation
│   ├── BSTRestaurant.cpp        # BST implementation
│   ├── City.cpp, District.cpp   # Geographic units
│   ├── Wilaya.cpp, Country.cpp  # Geographic hierarchy
│   ├── SalesAndCosts.cpp        # Sales/costs tracking
│   ├── Rating.cpp               # Rating system
│   └── PrizeWinners.cpp         # Prize management
├── include/                      # Header files (.h)
│   ├── Restaurant.h
│   ├── AVLRestaurant.h
│   ├── BSTRestaurant.h
│   ├── Date.h
│   └── [Geographic + Business entities]
├── Data/                         # Input data
│   ├── RESTAURANTS.csv          # Restaurant master data
│   ├── Ratings/                 # Customer ratings per restaurant
│   └── salesCosts/              # Sales and costs records
├── appendices/                   # Analysis & utilities
│   ├── profiling AVL vs BST/    # Performance comparison graphs
│   ├── restaurants generation/  # Data generation scripts
└── └── runtime of different functions/
```

---

## Core Data Structures

### Geographic Hierarchy
```
Country (Algeria)
  └── Wilaya (Province) [48]
        └── District (Daïra)
              └── City (Commune)
                    └── Restaurant
```

### Key Classes

| Class | Purpose |
|-------|---------|
| `Country` | Top-level container managing all Wilayas |
| `Wilaya` | Province management with districts |
| `District` | District management with cities |
| `City` | City management with restaurant collections |
| `Restaurant` | Restaurant entity with ID, name, cuisines |
| `AVLRestaurant` | AVL tree for efficient restaurant storage |
| `BSTRestaurant` | BST tree for comparative analysis |
| `SalesAndCosts` | Daily sales and cost records per cuisine |
| `Rating` | Monthly customer ratings per cuisine |
| `PrizeWinners` | Prize-winning restaurants and cumulative prizes |
| `Date` | Date management utility |

---

## Technical Highlights

### Data Structures Implemented
- **AVL Trees**: Self-balancing BST with height balance property
  - Insert: O(log n)
  - Search: O(log n)
  - Traversal: O(n)
  - Automatic rebalancing via rotations
  
- **Binary Search Trees**: Standard BST for comparison
  - Best case: O(log n)
  - Worst case: O(n)
  - Useful for understanding performance impact of balancing

### Algorithms
- **Tree rotations** (single and double) for AVL balancing
- **In-order traversal** for sorted restaurant/sales listings
- **Range queries** for geographic and date-based searches
- **Hierarchical insertion** maintaining geographic constraints
- **Prize calculation** with cumulative monthly tracking

### Performance Features
- Efficient memory management
- Lazy loading of restaurant data
- Optimized search queries
- Batch data import from CSV files
- Pre-computed aggregate statistics

---

## Performance Analysis

The project includes comprehensive performance profiling comparing AVL and BST implementations:

### Metrics Measured
- **Insert Operations**: Time complexity analysis for inserting 1000+ restaurants
- **Search Operations**: Query performance comparison for lookups
- **Tree Traversal**: Complete tree navigation performance
- **Memory Usage**: Comparative memory efficiency

### Results Location
- `appendices/profiling AVL vs BST/` contains:
  - `insertAVLvsBST.png` - Insert performance graph
  - `searchAVLvsBST.png` - Search performance graph
  - `TraversalAVLvsBST.png` - Traversal performance graph
  - Runtime logs for detailed analysis

### Key Findings
- AVL trees provide consistent O(log n) performance
- BST worst-case degradation visible with sequential insertions
- Trade-off between insertion cost and search efficiency

---

## Data Format

### RESTAURANTS.csv
```csv
ID,Name,WilayaCode,District,City,Cuisine1,Cuisine2,Cuisine3,Cuisine4,Cuisine5
1000031257,Restaurant Name,01,District1,City1,true,true,false,true,false
```

### Ratings Format
Each restaurant has cuisine ratings file: `[RestaurantID]ratings.csv`
```csv
Month,Cuisine1_Rating,Cuisine2_Rating,Cuisine3_Rating,Cuisine4_Rating,Cuisine5_Rating
2024-01,4.5,4.2,0,4.8,0
```

### Sales/Costs Format
`[RestaurantID]sales.csv` - Daily sales per cuisine
`[RestaurantID]costs.csv` - Daily cost breakdown

---

## Compilation & Execution

### Build the Project
```bash
cd /path/to/RCMS
g++ -std=c++17 src/*.cpp -I include -o build/rcms
```

### Run the Program
```bash
./build/rcms
```

### Compile with Optimization
```bash
g++ -std=c++17 -O2 src/*.cpp -I include -o build/rcms
```

### Debug Build
```bash
g++ -std=c++17 -g -O0 src/*.cpp -I include -o build/rcms_debug
```

---

## Usage Example

### Basic Program Flow
1. Initialize country hierarchy for Algeria
2. Load restaurant data from CSV files
3. Parse sales, costs, and ratings from data files
4. Insert restaurants into AVL/BST structures (comparable performance study)
5. Execute analytical queries:
   - Sales reports by date, cuisine, and geography
   - Prize winner identification
   - Publicity ROI calculations
6. Generate comprehensive reports and statistics

### Sample Queries Supported
```
- Sales report for restaurant X in month Y
- All restaurants in Wilaya Z with average rating > 4.0
- Top 10 prize winners for July 2024
- Sales-to-publicity ratio for all restaurants in district D
- Historical trends from date1 to date2
```

---


## Development Tools & Technologies

- **Language**: C++ (C++17 standard)
- **Compiler**: GCC/G++
- **Build System**: Manual compilation (G++)
- **Data Format**: CSV for all input files
- **Analysis Tools**: Python (matplotlib for performance graphs)
- **OS**: Linux
- **IDE**: VS Code with C++ extensions

---

## Additional Resources

### Appendices Included
1. **Performance Analysis**: Detailed profiling data and visualizations
   - AVL vs BST comparison charts
   - Runtime measurements for operations
2. **Data Generation Utilities**: Scripts for creating test datasets
3. **Sample Data**: CSV files with 1000+ restaurant records
4. **Analysis Results**: Runtime metrics and performance graphs
