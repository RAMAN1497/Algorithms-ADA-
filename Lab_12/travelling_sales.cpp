#include <iostream>
#include <vector>   
#include <climits>
using namespace std;
#define INF INT_MAX

int tsp(int pos, int mask, const vector<vector<int>> &dist, vector<vector<int>> &dp) {
    int n = dist.size();

    if (mask == (1 << n) - 1) {
        return dist[pos][0]; 
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city), dist, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int minCost = tsp(0, 1, dist, dp);
    cout << "Minimum cost of travelling salesman: " << minCost << endl;

    return 0;
}