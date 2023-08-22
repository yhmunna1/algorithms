#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    
}

const int N= 1e5+7;
int nums[N];

int binarySearch(int l, int r, int k)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == k)
            return mid;

        if (nums[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
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

    int result = binarySearch(0, n - 1, k);

    if (result != -1)
        cout << result << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}


// Input:
// 8
// -4 0 2 6 9 10 29 54
// 29
// Output:
// 6

// Input:
// 10
// 0 1 2 3 4 5 6 7 8 9
// -3
// Output:
// Not Found