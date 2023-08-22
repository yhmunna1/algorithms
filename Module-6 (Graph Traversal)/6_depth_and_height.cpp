#include <bits/stdc++.h>
using namespace std;
void init_code()
{
}

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    visited[u]= true;
    for(int v: adj[u])
    {
        if(visited[v]==true) continue;
        
        //Check Depth:
        depth[v] = depth[u]+1;


        dfs(v);

        // Check height:
        if(height[v]+1 > height[u])
        {height[u]=height[v]+1;}

        // Easy way
        // height[u] = max(height[u], height[v]+1);
    }
}

int main()
{
    init_code();

    int n,m;
    cin >>n >>m;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);     
    } 
    dfs(1);
    for (int i = 1; i <=n; i++)
    {
        cout << "Depth of Node " << i <<": "<<depth[i]<<endl;
    }
    for (int i = 1; i <=n; i++)
    {
        cout << "Height of Node " << i <<": "<<height[i]<<endl;
    }
    

    return 0;
}