# Algorithms

1. Activity Selection

Aim
Select maximum number of non-overlapping activities.

Algorithm
Sort activities by finish time

Select first activity

FOR each next activity:
    IF start >= last selected finish:
        select activity
Complexity
Case	Time	Space
Best	O(n log n)	O(1)
Average	O(n log n)	O(1)
Worst	O(n log n)	O(1)

Use Case
 Scheduling problems
 Resource allocation
 Event planning


2. Dijkstra Algorithm

Aim
Find shortest path from source to all vertices.

Algorithm
Initialize distances

FOR each vertex:
    pick minimum distance vertex

    update neighbors
Complexity
Case	Time	Space
Best	O(n²)	O(n)
Average	O(n²)	O(n)
Worst	O(n²)	O(n)

Use Case
 Routing
 Navigation
 Network optimization