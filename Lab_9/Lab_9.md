# Algorithms

1. Multistage Graph (Stage Identification)

Aim
Determine the number of stages in a graph by grouping nodes based on reachability.

Algorithm
Start with stage 0 containing source node
 
 WHILE new nodes are reachable:
    Add next reachable nodes as new stage

Complexity
Case	Time	Space
Best	O(n²)	O(n)
Average	O(n²)	O(n)
Worst	O(n²)	O(n)

Use Case
 Breaking problems into stages
 Pipeline processing
 Graph layering