#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    int mid = (high + low) / 2;
    cout << "low = " << low << " mid = " << mid << " high = " << high << "\n";
    while (low <= high)
    {
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
        {
            high = mid - 1;
            mid = (high + low) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (high + low) / 2;
        }

        cout << "low = " << low << " mid = " << mid << " high = " << high << "\n";
    }

    return -1;
}

int main()
{
    int arr1[] = {4, 3, 5, 6, 4, 3, 5, 6, 9, 10};
    int arr2[6] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << binarySearch(arr2, 6, -1);
}