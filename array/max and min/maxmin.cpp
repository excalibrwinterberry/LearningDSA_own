#include <bits/stdc++.h>

using namespace std;

int main()
{

    int arr[] = {4, 3, 5, 6, 4, 3, 5, 6, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minNo = INT_MAX;
    int maxNo = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maxNo = max(arr[i], maxNo);
        minNo = min(minNo, arr[i]);
    }
    cout << "Max: " << maxNo << "\nMin: " << minNo;
}