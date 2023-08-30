#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<string> &matrix, int i, int j, int di, int dj)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == '-' || matrix[i][j] == 'x')
    {
        return false;
    }

    if (i == di && j == dj)
    {
        return true;
    }

    matrix[i][j] = 'x';

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int k = 0; k < 4; ++k)
    {
        if (dfs(matrix, i + dx[k], j + dy[k], di, dj))
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

    if (dfs(matrix, si, sj, di, dj))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
