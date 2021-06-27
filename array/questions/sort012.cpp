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

// to sort an array containing 0 1 2
// aka Dutch national flag problem
// there are 3 approaches:
// 1. Brute Force: sort the array, tc => O(nlogn)
// 2. Counting 0 1 2: we keep a count of 0 1 and 2 in 3 different varibles and fill the array as per the numbers of  0 1 2
// 3. Maintainig low mid and high pointer: we maintain 3 pointers low mid = 0 and high = n-1. the logic is that [0...low-1] = 0 and [high+1....n-1] = 2

// will only code 2nd and thrid approach

void dnf1(int arr[], int n)
{
    int a0 = 0, a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
            a0++;
        else if (arr[i] == 1)
            a1++;
        else
            a2++;
    }

    a1 += a0;
    a2 += a1;

    for (int i = 0; i < n; ++i)
    {
        if (i < a0)
        {
            arr[i] = 0;
        }
        else if (i < a1)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 2;
        }
    }
}

void dnf2(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    cout << "low = " << low << " mid = " << mid << " high = " << high << "\n";
    display(arr, n);
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++, low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        cout << "low = " << low << " mid = " << mid << " high = " << high << "\n";
        display(arr, n);
        cout << "\n";
    }
}

int main()
{
    int arr[6] = {2, 0, 2, 1, 1, 0};
    dnf2(arr, 6);
}