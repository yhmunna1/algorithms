#include <bits/stdc++.h>
using namespace std;

const int N = 21;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u]= true;
    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}


int main()
{

    int n,m;
    cin >>n >>m;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;

    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    dfs(k);
    int count = 0;
    for (int v : adj[k]) {
        if (visited[v]) {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}