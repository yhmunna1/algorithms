#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    for (int i = 0; i < e; i++)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        Edge edge(a, b, w);
        edges.push_back(edge);
    }

    long long int source;
    cin >> source;

    long long int t;
    cin >> t;

    while (t--)
    {
        long long int destination;
        cin >> destination;

        vector<long long int> distance(n + 1, INT_MAX);
        distance[source] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            for (Edge &edge : edges)
            {
                if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.w < distance[edge.v])
                {
                    distance[edge.v] = distance[edge.u] + edge.w;
                }
            }
        }

        bool hasNegativeCycle = false;
        for (Edge &edge : edges)
        {
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.w < distance[edge.v])
            {
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (distance[destination] == INT_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << distance[destination] << endl;
        }
    }

    return 0;
}
