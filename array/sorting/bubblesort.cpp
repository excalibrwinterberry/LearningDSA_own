#include <iostream>
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

void bubbleSort(int arr[], int n)
{ // bubbling the largest element to the last place and doing it n-1 times

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        display(arr, 6);
    }
}

int main()
{
    int arr[6] = {5, 3, 1, 4, 6, 2};
    bubbleSort(arr, 6);
    display(arr, 6);
}