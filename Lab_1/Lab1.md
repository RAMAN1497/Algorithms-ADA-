# Algorithm 


1. Bubble Sort

Aim
To sort an array of integers in ascending order by repeatedly comparing and swapping adjacent elements until the array is fully sorted.

Algorithm 

BubbleSort(arr, n):
  FOR i = 0 TO n-2:
    FOR j = 0 TO n-i-2:
      IF arr[j] > arr[j+1]:
        SWAP(arr[j], arr[j+1])


Time & Space Complexity
| Case | Time Complexity |
|------|----------------|
| Best | O(n) — already sorted (with optimization) |
| Average | O(n²) |
| Worst | O(n²) |

Space Complexity:O(1) — in-place sorting

Use Cases
- Educational purposes to understand sorting fundamentals
- Small datasets where simplicity matters over efficiency


---

 2. Selection Sort

Aim
To sort an array by repeatedly finding the minimum element from the unsorted portion and placing it at the beginning.

Algorithm
```
SelectionSort(arr, n):
  FOR i = 0 TO n-2:
    minIdx = i
    FOR j = i+1 TO n-1:
      IF arr[j] < arr[minIdx]:
        minIdx = j
    SWAP(arr[i], arr[minIdx])
```

 Time & Space Complexity
| Case | Time Complexity |
|------|----------------|
| Best | O(n²) |
| Average | O(n²) |
| Worst | O(n²) |

Space Complexity: O(1) — in-place sorting

 Use Cases
- Small datasets where memory writes are expensive (fewer swaps than Bubble Sort)
- Embedded systems with very limited memory

---

3. Horner's Rule

 Aim
To efficiently evaluate a polynomial at a given value of x using Horner's method, which reduces the number of multiplications needed compared to naive evaluation.

 Algorithm
```
Horner(coeff[], n, x, i):
  IF i == n:
    RETURN coeff[n]
  RETURN coeff[i] + x * Horner(coeff, n, x, i+1)

// Evaluates: coeff[0] + x*(coeff[1] + x*(coeff[2] + ... + x*coeff[n]))
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(n) |
| Space | O(n) — due to recursive call stack |

Naive evaluation: O(n²) multiplications — Horner's reduces it to O(n).

 Use Cases
- Polynomial evaluation in mathematical computations
- Compiler design and expression parsing
- Numerical methods and scientific computing


---

4. Linear Search

 Aim
To find a target element in an unsorted array by scanning each element sequentially from the beginning until the target is found or the array is exhausted.

 Algorithm 
```
LinearSearch(arr, n, target):
  FOR i = 0 TO n-1:
    IF arr[i] == target:
      RETURN i       // Found at index i
  RETURN -1          // Not found
```

 Time & Space Complexity
| Case | Time Complexity |
|------|----------------|
| Best | O(1) — target is the first element |
| Average | O(n) |
| Worst | O(n) — target not present |

Space Complexity: O(1)

 Use Cases
- Searching in unsorted or unindexed data
- Small datasets where sorting overhead is not justified
- One-time searches where preprocessing is not worth it

---

5. Missing Number

 Aim
To find the missing number in a sorted consecutive integer array using the Least Significant Bit (LSB) parity property — consecutive integers alternate between odd and even, so a missing number breaks this alternating pattern.

 Algorithm 
```
FindMissing(arr, n):
  FOR i = 0 TO n-2:
    IF (arr[i] & 1) == (arr[i+1] & 1):
      RETURN (arr[i] + arr[i+1]) / 2
  RETURN -1   // No missing number found
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(n) |
| Space | O(1) |

 Use Cases
- Data validation in sequential ID systems
- Detecting gaps in sorted record sequences
- Network packet loss detection (sequential packet IDs)


---

6. Permutation

 Aim
To generate all permutations of a given string or sequence using recursive backtracking by swapping characters and exploring all orderings.

 Algorithm 
```
Permute(s, l, r):
  IF l == r:
    OUTPUT s        // One complete permutation found
    RETURN
  FOR i = l TO r:
    SWAP(s[l], s[i])
    Permute(s, l+1, r)
    SWAP(s[l], s[i])  // Backtrack — restore original
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(n × n!) — n! permutations, each taking O(n) to build |
| Space | O(n) — recursion depth equals string length |

 Use Cases
- Generating all possible arrangements (anagram solving)
- Solving combinatorial optimization problems (e.g., Travelling Salesman Problem brute force)
- Password/key generation and cryptographic analysis

---

7. Power of x^n (Fast Exponentiation)

 Aim
To compute x raised to the power n efficiently using binary exponentiation (Divide and Conquer), reducing the number of multiplications from O(n) to O(log n).

 Algorithm
```
Power(x, n):
  IF n == 0:
    RETURN 1
  half = Power(x, n/2)
  IF n is EVEN:
    RETURN half * half
  ELSE:
    RETURN x * half * half
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(log n) |
| Space | O(log n) — recursive call stack depth |

Naive approach: O(n) — multiplying x by itself n times.

 Use Cases
- Modular exponentiation in cryptography (RSA, Diffie-Hellman)
- Computing large powers in competitive programming


---

8. Tips from Velocity

 Aim
To determine the number of "tips" (discrete steps) taken as a velocity value decays repeatedly by a fixed fraction (55.5% each step) until it drops below 1.0, using recursion.

 Algorithm 
```
FindTips(v):
  IF v < 1.0:
    RETURN 0
  RETURN 1 + FindTips(v - 0.425 * v)

// Each recursive call: v_new = v * (1 - 0.425) = v * 0.575
// Continues until v drops below 1.0
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(log v) — velocity reduces geometrically by factor 0.575 each step |
| Space | O(log v) — recursive call stack |



 Use Cases
- Simulating physical deceleration models (friction, drag)
- Modelling exponential decay processes
- Game mechanics involving velocity reduction per frame or per event


---

9. Tower of Hanoi

 Aim
To move a stack of n disks from a source peg to a destination peg using an auxiliary peg, following the rule that no larger disk may be placed on a smaller one, using recursion.

 Algorithm 
```
Hanoi(n, source, auxiliary, destination):
  IF n == 0:
    RETURN
  Hanoi(n-1, source, destination, auxiliary)   // Move n-1 disks to auxiliary
  MOVE disk n from source TO destination        // Move largest disk
  Hanoi(n-1, auxiliary, source, destination)   // Move n-1 disks to destination
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(2ⁿ) — exactly 2ⁿ − 1 moves required |
| Space | O(n) — recursion depth equals number of disks |

 Use Cases
- Classic example for teaching recursion and divide-and-conquer
- Backup rotation strategies in IT (grandfather-father-son scheme)


---

10. Truth Table 

 Aim
To generate the complete truth table for n boolean variables using recursive backtracking, assigning True and False to each variable and exploring all 2ⁿ combinations.

 Algorithm
```
BTT(k, n):
  IF k > n:
    OUTPUT a[1..n]    // Print one complete row of the truth table
    RETURN
  a[k] = TRUE
  BTT(k+1, n)         // Recurse with T assigned to variable k

  a[k] = FALSE
  BTT(k+1, n)         // Recurse with F assigned to variable k
```

 Time & Space Complexity
| Metric | Complexity |
|--------|-----------|
| Time | O(2ⁿ) — generates all 2ⁿ combinations |
| Space | O(n) — recursion depth + array of size n |

 Use Cases
- Boolean logic verification and digital circuit design
- Automated theorem proving and SAT solving
- Generating test cases for logical expressions

---

