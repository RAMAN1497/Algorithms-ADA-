#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 10000000;

vector< set<int> > s;

void findStage(vector<vector<int>> &g) {
    int i = 0;

    set<int> t;
    t.insert(0);
    s.push_back(t);

    while (i < s.size()) {
        set<int> st;

        for (int e : s[i]) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[e][j] != 0 && g[e][j] != INF) {
                    st.insert(j);
                }
            }
        }

        if (!st.empty()) {
            s.push_back(st);
        }
        i++;
    }

    cout << "Number of stages = " << s.size() << endl;
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

    findStage(g);


    return 0;
}