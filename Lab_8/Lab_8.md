# Algorithms

1. Cycle Detection

Aim
Detect whether a cycle exists in an undirected graph using Depth First Search (DFS).

Algorithm
DFS(node, parent):
    Mark node as visited

    FOR each neighbor:
        IF not visited:
            IF DFS(neighbor, node) → true:
                RETURN true
        ELSE IF neighbor != parent:
            RETURN true

    RETURN false

Complexity
Case	Time	Space
Best	O(V+E)	O(V)
Average	O(V+E)	O(V)
Worst	O(V+E)	O(V)

Use Case
 Detect loops in networks
 Graph validation
 Deadlock detection


2. Dijkstra Algorithm

Aim
Find the shortest path from a source node to all other nodes in a weighted graph.

Algorithm
Initialize dist[] = INF, dist[src] = 0

FOR n-1 times:
    Pick unvisited node with minimum distance

    FOR each neighbor:
        IF shorter path found:
            update distance
            update parent
Complexity
Case	Time	Space
Best	O(n²)	O(n)
Average	O(n²)	O(n)
Worst	O(n²)	O(n)

Can be optimized to O((V+E) log V) using priority queue.

Use Case
 GPS navigation systems
 Network routing
 Shortest path problems