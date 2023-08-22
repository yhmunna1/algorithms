#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        leaders.push_back(i);
        dfs(i);
    }

    // Print:
    cout << leaders.size() - 1 << endl;
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }

    return 0;
}

/*
Input: 1
4 2
1 2
3 4
*/

/*
Input: 2
8 4
1 2
3 4
5 6
5 7
*/
