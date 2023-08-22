#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    
}

const int N = 1e5 + 7;
int nums[N];

int findFirstOccurrence(int l, int r, int k)
{
    int result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == k)
        {
            result = mid;
            r = mid - 1;
        }
        else if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int findLastOccurrence(int l, int r, int k)
{
    int result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == k)
        {
            result = mid;
            l = mid + 1;
        }
        else if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int main()
{
    init_code();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int firstOccurrence = findFirstOccurrence(0, n - 1, k);
    int lastOccurrence = findLastOccurrence(0, n - 1, k);

    if (firstOccurrence != lastOccurrence)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


// Input:
// 7
// 1 3 4 6 6 9 17		
// 6
// Output:
// YES
// Input:
// 10
// 0 1 2 3 4 5 6 7 8 9
// 3
// Output:
// NO