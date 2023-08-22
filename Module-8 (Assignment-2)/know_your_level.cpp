#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int node, int level, vector<int>& pizzaShops) {
    visited[node] = true;

    if (level == 0) {
        pizzaShops.push_back(node);
        return;
    }

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, level - 1, pizzaShops);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int level;
    cin >> level;

    vector<int> pizzaShops;
    memset(visited, false, sizeof(visited));

    dfs(0, level, pizzaShops);

    if (pizzaShops.empty()) {
        cout << -1 << endl;
    } else {
        sort(pizzaShops.begin(), pizzaShops.end());
        for (int shop : pizzaShops) {
            cout << shop << " ";
        }
        cout << endl;
    }

    return 0;
}
