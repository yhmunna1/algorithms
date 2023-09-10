#include <bits/stdc++.h>
using namespace std;

bool canReach(int curr, int target)
{
    if (curr == target)
    {
        return true;
    }

    if (curr > target)
    {
        return false;
    }
    return canReach(curr + 3, target) || canReach(curr * 2, target);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        bool result = canReach(1, N);
        if (result)
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
