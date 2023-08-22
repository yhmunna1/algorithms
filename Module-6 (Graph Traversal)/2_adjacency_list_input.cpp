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
// vector<int> adj[N];
vector<pair<int, int> > adj[N];

int main()
{
    init_code();

    int n,m;
    cin >>n >>m;

    for (int i = 0; i < m; i++)
    {
        /*
        int u,v;
        cin >>u >>v;
        */
        int u,v, w;
        cin >>u >>v>> w;
        adj[u].push_back({v,w});
        // adj[u].push_back({u,w});     
    }

    for (int i = 1; i <=n; i++)
    {
        cout<< "List" <<i <<": ";
        for (auto j:adj[i])
        {
            cout<<"("<<j.first;
            cout<<", " << j.second<< "),";
        }
        cout <<endl;
    }
    return 0;
}


/*
4
5
1 2 9
1 3 9
2 4 11
4 3 17
3 2 15
*/