#include <bits/stdc++.h>
using namespace std;

void init_code() {
}

const int N = 1e5 + 7;
int arr1[N], arr2[N], result[2 * N];

void merge(int len1, int len2) {
    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        if (arr1[i] >= arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < len2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    init_code();

    int len1, len2;
    cin >> len1;
    for (int i = 0; i < len1; i++) {
        cin >> arr1[i];
    }

    cin >> len2;
    for (int i = 0; i < len2; i++) {
        cin >> arr2[i];
    }

    merge(len1, len2);

    for (int i = 0; i < len1 + len2; i++) {
        cout << result[i] << " ";
    }

    return 0;
}


// Input:
// 4
// 8 6 4 2	
// 4
// 7 5 3 1

// Output:
// 8 7 6 5 4 3 2 1