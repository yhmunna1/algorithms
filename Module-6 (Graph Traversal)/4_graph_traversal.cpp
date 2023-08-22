#include <bits/stdc++.h>
using namespace std;
void init_code()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u]= true;
    cout<< "Visiting Nose: " <<u << endl;
    for(int v: adj[u])
    {
        if(visited[v]==true) continue;
        dfs(v);
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
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<< "Node" <<i <<": ";
    //     for (int j:adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout <<endl;
    // }
    dfs(1);

    cout << "Visiting Array\n";
    for (int i = 1; i <=n; i++)
    {
        cout <<"Node" << i<< "Status: "<< visited[i]<< endl;
    }
    

    return 0;
}


/*
10
9
1 2
1 3
1 10
2 4
3 5
4 7
4 8
6 9
*/

/*
9
10
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9
*/