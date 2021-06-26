#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[7] = {1, 4, 2, 5, 7, 1, 9};
    int maxNo = INT_MIN;
    for (int i = 0; i < 7; ++i)
    {
        maxNo = max(arr[i], maxNo);
        arr[i] = maxNo;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}