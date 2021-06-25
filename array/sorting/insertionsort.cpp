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

void insertionSort(int arr[], int n)
{ // checking with the previous values and placing it in its correct place, making the array before the element sorted
    for (int i = 1; i < n; ++i)
    {
        cout << "i=" << i << "\n";
        int curr = arr[i];
        int j = i - 1;
        cout << "j=" << j << "\n";
        display(arr, 6);
        while (arr[j] > curr && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            cout << "j=" << j << "\n";

            display(arr, 6);
        }
        arr[j + 1] = curr;
        display(arr, 6);
    }
}

int main()
{
    int arr[6] = {5, 3, 1, 4, 6, 2};
    insertionSort(arr, 6);
    display(arr, 6);
}