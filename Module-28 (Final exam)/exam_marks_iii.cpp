#include <bits/stdc++.h>
using namespace std;

int minMarksFun(int N, int targetSum, vector<int> &marks)
{
    vector<int> dp(targetSum + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = marks[i]; j <= targetSum; j++)
        {
            if (dp[j - marks[i]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - marks[i]] + 1);
            }
        }
    }

    return dp[targetSum] == INT_MAX ? -1 : dp[targetSum];
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
        int minMarks = minMarksFun(N, targetSum, marks);

        cout << minMarks << endl;
    }

    return 0;
}
