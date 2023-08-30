#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<string> matrix;
bool visited[N][N];
int componentSize;

bool isValid(int i, int j)
{
    return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] == '.';
}

void dfs(int i, int j)
{
    visited[i][j] = true;
    componentSize++;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++)
    {
        int ni = i + dr[dir];
        int nj = j + dc[dir];
        if (isValid(ni, nj) && !visited[ni][nj])
        {
            dfs(ni, nj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    matrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    int minArea = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && matrix[i][j] == '.')
            {
                componentSize = 0;
                dfs(i, j);
                minArea = min(minArea, componentSize);
            }
        }
    }

    if (minArea == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minArea << endl;
    }

    return 0;
}
