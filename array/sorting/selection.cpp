#include <iostream>
#include <climits>
#include <array>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int a = INT_MAX, k = i + 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (a > arr[j])
            {
                k = j;
                a = arr[j];
            }
        }
        if (arr[i] > arr[k])
        {
            swap(arr[i], arr[k]);
        }
        display(arr, n);
    }
}

int main()
{
    int arr[6] = {5, 3, 1, 4, 6, 2};
    display(arr, 6);
    selectionSort(arr, 6);
    // int choc = 15, wrap = 15;
    // while (wrap >= 3)
    // {
    //     choc += wrap / 3;
    //     wrap = wrap / 3 + wrap % 3;
    //     cout << "choco = " << choc << " wrap = " << wrap << "\n";
    // }
}