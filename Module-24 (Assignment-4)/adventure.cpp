#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[N][W];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, W;
        cin >> N >> W;

        vector<int> weights(N);
        vector<int> values(N);

        for (int i = 0; i < N; i++)
        {
            cin >> weights[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin >> values[i];
        }

        int result = knapsack(N, W, weights, values);
        cout << result << endl;
    }

    return 0;
}
