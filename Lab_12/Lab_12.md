# Algorithms

1. Traveling Salesperson Problem (Dynamic Programming + Bitmasking)

Aim
Efficiently find the minimum cost of visiting all cities exactly once and returning to the starting city using Dynamic Programming with Bitmasking.

Algorithm
TSP(pos, mask):
    IF mask == (1 << n) - 1:
        RETURN dist[pos][0]

    IF dp[pos][mask] != -1:
        RETURN dp[pos][mask]

    ans = INF

    FOR each city from 0 to n-1:
        IF city is not visited in mask:
            newAns = dist[pos][city] + TSP(city, mask | (1 << city))
            ans = min(ans, newAns)

    RETURN dp[pos][mask] = ans
Complexity
Case	Time	Space
Best	O(n² · 2ⁿ)	O(n · 2ⁿ)
Average	O(n² · 2ⁿ)	O(n · 2ⁿ)
Worst	O(n² · 2ⁿ)	O(n · 2ⁿ)

TSP using DP + Bitmasking significantly reduces complexity from O(n!) → O(n²·2ⁿ).
Still expensive, but feasible for n ≤ 20.

Use Case
 Route optimization (delivery, logistics)
 Traveling route planning
 Circuit design (minimizing wiring distance)
 Genome sequencing (bioinformatics)
