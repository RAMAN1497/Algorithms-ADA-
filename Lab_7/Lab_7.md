# Algorithms

1. Kruskal Algorithm

Aim
Find Minimum Spanning Tree using greedy approach.

Algorithm
Sort edges by weight

FOR each edge:
    IF no cycle:
        include edge
Complexity
Case	Time	Space
Best	O(E log E)	O(V)
Average	O(E log E)	O(V)
Worst	O(E log E)	O(V)
 Use Case
 Network design
 Road planning
 Cable layout


2. Prim Algorithm

Aim
Find Minimum Spanning Tree starting from a vertex.

Algorithm
Start from a vertex

REPEAT:
    pick minimum edge connecting tree to new vertex
Complexity
Case	Time	Space
Best	O(n²)	O(n)
Average	O(n²)	O(n)
Worst	O(n²)	O(n)
 
Use Case
 Network design
 Infrastructure planning
 Graph optimization