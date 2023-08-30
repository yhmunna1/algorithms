#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(vector<string> &matrix, vector<vector<bool>> &visited, int i, int j, int di, int dj)
{
    if (!is_valid(i, j, matrix.size(), matrix[0].size()) || visited[i][j] || matrix[i][j] == '-')
    {
        return false;
    }

    visited[i][j] = true;
    if (i == di && j == dj)
    {
        return true;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int k = 0; k < 4; ++k)
    {
        if (dfs(matrix, visited, i + dx[k], j + dy[k], di, dj))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> matrix(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i];
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    if (dfs(matrix, visited, si, sj, di, dj))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
