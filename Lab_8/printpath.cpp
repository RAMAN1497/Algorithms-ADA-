#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

void printPath(vector<int> &parent, int j) {
    if (j == -1)
        return;

    printPath(parent, parent[j]);
    cout << j << " ";
}

void dijkstra(vector<vector<int>> &g, int src) {
    int n = g.size();

    vector<int> dist(n, INF);   
    vector<bool> visited(n, false); 
    vector<int> parent(n, -1); 

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && g[u][v] != 0 && g[u][v] != INF) {
                if (dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nShortest paths from source " << src << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "To node " << i << " (Distance = " << dist[i] << "): Path = ";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    cout << "Enter adjacency matrix (0 or INF if no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(g, src);

    return 0;
}