#include <iostream>
#include <climits>
using namespace std;

int longestSumSubarray(int arr[], int n)
{
    int pd = arr[1] - arr[0];
    int count = 1, sum = 0, fcount = 0;
    int currSum = arr[0];
    cout << "pd = " << pd << " count = " << count << " fcount = " << fcount << " currSum= " << currSum << " sum = " << sum << "\n";
    for (int i = 1; i < n; i++)
    {
        if (pd == arr[i] - arr[i - 1])
        {
            currSum += arr[i];
            count += 1;
        }
        else
        {
            if (currSum > sum)
            {
                fcount = count;
                sum = currSum;
            }
            count = 2;
            currSum = arr[i] + arr[i - 1];
            pd = arr[i] - arr[i - 1];
        }
        cout << "pd = " << pd << " count = " << count << " fcount = " << fcount << " currSum= " << currSum << " sum = " << sum << "\n";
    }
    if (currSum > sum)
    {
        fcount = count;
        sum = currSum;
    }

    return fcount;
}

int main()
{
    int arr[7] = {10, 7, 4, 6, 8, 10, 11};
    cout << longestSumSubarray(arr, 7);
}