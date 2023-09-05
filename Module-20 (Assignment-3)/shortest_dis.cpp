#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
int dis[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();
        int currentNode = current.second;
        int currentCost = current.first;

        if (currentCost > dis[currentNode])
        {
            continue;
        }

        for (pair<int, int> neighbor : v[currentNode])
        {
            int neighborNode = neighbor.first;
            int neighborCost = neighbor.second;
            if (dis[currentNode] + neighborCost < dis[neighborNode])
            {
                dis[neighborNode] = dis[currentNode] + neighborCost;
                pq.push({dis[neighborNode], neighborNode});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = INT_MAX;
        }
        dijkstra(x);

        if (dis[y] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[y] << endl;
        }
    }

    return 0;
}
