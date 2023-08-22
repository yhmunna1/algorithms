#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int dist[N];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
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

    int q;
    cin >> q;

    while (q--) {
        int source, dest;
        cin >> source >> dest;

        for (int i = 0; i < N; i++) {
            visited[i] = false;
            dist[i] = -1;
        }

        bfs(source);

        if (dist[dest] != -1) {
            cout << dist[dest] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
