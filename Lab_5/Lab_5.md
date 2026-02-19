# Algorithms

1. Convex Hull

Aim
Find the smallest convex polygon enclosing all given points.

Algorithm
Divide points into left and right halves

Recursively find convex hull of both halves

Merge two hulls:
    Find upper tangent
    Find lower tangent
    Combine hulls
Complexity
Case	Time	Space
Best	O(n log n)	O(n)
Average	O(n log n)	O(n)
Worst	O(n log n)	O(n)

Use Case
 Computer graphics
 GIS systems
 Collision detection


2. Knapsack Problem

Aim
Maximize profit by selecting items with given weights and profits (fraction allowed).

Algorithm
Sort items based on:
    profit/weight OR profit OR weight

FOR each item:
    IF weight <= capacity:
        take whole item
    ELSE:
        take fraction
        break
Complexity
Case	Time	Space
Best	O(n log n)	O(1)
Average	O(n log n)	O(1)
Worst	O(n log n)	O(1)

Greedy approach.

Use Case
 Resource allocation
 Budget optimization
 Cargo loading


3. Matrix Multiplication

Aim
Multiply two matrices using divide and conquer approach.

Algorithm
Divide matrices into 4 submatrices

Recursively compute:
    C11 = A11*B11 + A12*B21
    C12 = A11*B12 + A12*B22
    C21 = A21*B11 + A22*B21
    C22 = A21*B12 + A22*B22

Combine results
Complexity
Case	Time	Space
Best	O(n³)	O(n²)
Average	O(n³)	O(n²)
Worst	O(n³)	O(n²)

Use Case
 Scientific computing
 Graphics transformations
 Linear algebra


4. Strassen Algorithm

Aim
Multiply matrices faster than standard method using divide and conquer.

Algorithm
Divide matrices

 Compute 7 products:
  M1 to M7
 Combine to get C matrix

Complexity
Case	Time	Space
Best	O(n^2.81)	O(n²)
Average	O(n^2.81)	O(n²)
Worst	O(n^2.81)	O(n²)

Use Case
 Large matrix multiplication
 Scientific simulations
 Performance-critical systems