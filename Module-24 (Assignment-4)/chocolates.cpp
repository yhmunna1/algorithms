#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> chocolates(N);
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> chocolates[i];
            total += chocolates[i];
        }
        bool possible = (total % 2 == 0);
        if (possible)
        {
            int half_total = total / 2;
            vector<bool> dp(half_total + 1, false);
            dp[0] = true;

            for (int i = 0; i < N; i++)
            {
                for (int j = half_total; j >= chocolates[i]; j--)
                {
                    dp[j] = dp[j] || dp[j - chocolates[i]];
                }
            }

            if (!dp[half_total])
            {
                possible = false;
            }
        }
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
