#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int maxMarksFun(int N, int targetSum, vector<int> &marks)
{
    vector<int> dp(targetSum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = marks[i]; j <= targetSum; j++)
        {
            dp[j] = (dp[j] + dp[j - marks[i]]) % MOD;
        }
    }

    return dp[targetSum];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        int totalMarks = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> marks[i];
            totalMarks += marks[i];
        }

        int targetSum = 1000 - M;
        int maxWays = maxMarksFun(N, targetSum, marks);

        cout << maxWays << endl;
    }

    return 0;
}
