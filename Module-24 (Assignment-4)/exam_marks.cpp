#include <bits/stdc++.h>
using namespace std;

bool canAchieveTotalSum(int N, int targetSum, vector<int> &marks)
{
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = targetSum; j >= marks[i]; j--)
        {
            dp[j] = dp[j] || dp[j - marks[i]];
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
        bool possible = canAchieveTotalSum(N, targetSum, marks);

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
