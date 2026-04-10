# Algorithms

1. Matrix Chain Multiplication

Aim
Determine the most efficient way to multiply a chain of matrices by minimizing scalar multiplications.

Algorithm
FOR length = 2 to n:
    FOR i = 1 to n-length+1:
        j = i + length - 1
        dp[i][j] = INF

        FOR k = i to j-1:
            cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]
            dp[i][j] = min(dp[i][j], cost)
            s[i][j] = k
Complexity
Case	Time	Space
Best	O(n³)	O(n²)
Average	O(n³)	O(n²)
Worst	O(n³)	O(n²)

Uses Dynamic Programming (Bottom-Up) approach.
Also provides optimal parenthesization.

Use Case
 Compiler optimization
 Expression evaluation
 Database query optimization


2. Multistage Graph

Aim
Find the shortest path from source to destination in a multistage graph using dynamic programming.

Algorithm
mcost[n-1] = 0

FOR i = n-2 to 0:
    mcost[i] = INF

    FOR j = i+1 to n-1:
        IF edge exists:
            mcost[i] = min(mcost[i], cost[i][j] + mcost[j])
            d[i] = j
Complexity
Case	Time	Space
Best	O(n²)	O(n)
Average	O(n²)	O(n)
Worst	O(n²)	O(n)

Works only on Directed Acyclic Graph (DAG) divided into stages.

Use Case
 Resource allocation problems
 Stage-wise decision problems
 Pipeline optimization