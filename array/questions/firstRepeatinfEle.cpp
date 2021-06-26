#include <iostream>
#include <climits>
using namespace std;

int indexFirstRepeatingEle(int arr[], int n)
{
    int idx[99];
    fill_n(idx, 99, -1);
    int minIndx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == -1)
        {
            idx[arr[i]] = i;
        }
        else
        {
            minIndx = min(minIndx, idx[arr[i]]);
        }
    }
    minIndx = minIndx == INT_MAX ? -1 : minIndx;
    return minIndx;
}

int main()
{
    int arr[7] = {1, 5, 3, 4, 8, 6, 6};
    cout << indexFirstRepeatingEle(arr, 7);
}