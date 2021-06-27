#include <iostream>
#include <array>
#include <cmath>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void sort2arr(int arr1[], int n, int arr2[], int m)
{
    // O(1) space
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            int j = 0;
            while (j < m - 1)
            {
                if (arr2[j] > arr2[j + 1])
                {
                    swap(arr2[j], arr2[j + 1]);
                    j++;
                }
                else
                    break;
            }
        }
    }
    display(arr1, n);
    display(arr2, m);
}

int main()
{
    int arr1[4] = {1, 3, 4, 5}, arr2[3] = {2, 6, 8};
    sort2arr(arr1, 4, arr2, 3);
}