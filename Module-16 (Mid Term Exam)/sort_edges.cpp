#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    cin >> e;

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    sort(edges.begin(), edges.end());

    for (const auto &edge : edges)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
