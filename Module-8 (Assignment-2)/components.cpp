#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &size) {
    visited[u] = true;
    size++;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, size);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> componentSizes;
    for (int i = 1; i < N; i++) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, size);
            if (size > 1) {
                componentSizes.push_back(size);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes) {
        cout << size << " ";
    }

    return 0;
}
