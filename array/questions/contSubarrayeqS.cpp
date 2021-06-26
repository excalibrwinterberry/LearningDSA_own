#include <iostream>
#include <climits>
using namespace std;

void contSubArray(int arr[], int n, int s)
{
    int sumArr[n + 1] = {0};
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        sumArr[i] = arr[i - 1] + sumArr[i - 1];
        if (sumArr[i] >= s)
        {
            if (k == 0)
                k = i;
        }
    }

    while (k <= n)
    {
        cout << "k = " << k;
        for (int i = 0; i < k; ++i)
        {
            cout << "\ni = " << i;
            cout << " subArr[k] = " << sumArr[k] << " subArr[i] = " << sumArr[i];
            if (sumArr[k] - sumArr[i] == s)
            {
                cout << "\nans = " << i + 1 << " " << k;
                return;
            }
            cout << "\n";
        }

        k++;
    }
}

int main()
{
    int arr[5] = {1, 2, 4, 7, 5};
    contSubArray(arr, 5, 12);
}