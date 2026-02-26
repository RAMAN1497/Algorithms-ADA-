#include <iostream>
#include <climits>
using namespace std;

#define M 4
const int INF = INT_MAX / 2;

void dijkstra(int graph[M][M], int start) {
    int dist[M];
    bool visited[M] = {false};

    for (int i = 0; i < M; ++i) {
        if (graph[start][i] == -1)
            dist[i] = INF;
        else
            dist[i] = graph[start][i];
    }
    dist[start] = 0;

    for (int count = 0; count < M - 1; ++count) {
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < M; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < M; ++v) {
            if (!visited[v] && graph[u][v] != -1) {
                int alt = dist[u] + graph[u][v];
                if (alt < dist[v]) dist[v] = alt;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        if (dist[i] >= INF)
            cout << "No path from " << start << " to " << i << "\n";
        else
            cout << "The shortest path from " << start << " to " << i << " is " << dist[i] << "\n";
    }
}

int main() {
    int graph[M][M];
    cout << "Enter adjacency matrix (use -1 for no edge):\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << "element [" << i << "][" << j << "]: ";
            cin >> graph[i][j];
        }
    }
    int start;
    cout << "Enter starting vertex (0.." << M-1 << "): ";
    cin >> start;
    dijkstra(graph, start);
    return 0;
}