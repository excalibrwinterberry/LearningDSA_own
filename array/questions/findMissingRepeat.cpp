#include <iostream>
#include <array>
using namespace std;

// In an array there are nos from range 1-n except 1 no. and 1 no. is repeating. to find the missing and repeatind element
// 1. sort the array : O(nlogn)
// 2. create and array and store the no. of times an element is present in the og array: tc = O(N) , sc = O(N)
// 2.1 modifying the previous algo by managing in the same array => for every element in array = ele ,visit array[ele] and turn it to -ve if it is +ve. -ve means the number is visited
//  which in turn means that the index is used twice so the index which is ele is repeated. the element which still remains +ve has the index as the missing number
// 3. let x and y be 2 nos. X-Y = sum of array - sum[1-n] and X^2 - Y^2 = sum of ele^2 of array - sum of [1^2-n^2]=> now X+Y is know. solve for x and y :  tc = O(N) , sc = O(1)
// 4. using bitwise operator

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void findTwoElement2(int arr[], int n)
{
    int tempArr[n] = {0};
    int ans[2];
    for (int i = 0; i < n; i++)
    {
        tempArr[arr[i] - 1] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (tempArr[i] == 0)
        {
            ans[1] = i + 1;
        }
        else if (tempArr[i] == 2)
        {
            ans[0] = i + 1;
        }
    }

    cout << "Missing No. = " << ans[0] << "\nRepeating No. =  " << ans[1];
}

void findTwoElement21(int arr[], int n)
{
    int me = 0, re = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i] - 1)] *= -1;
        }
        else
        {
            re = arr[i];
            arr[i] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            me = i + 1;
    }

    cout << "Missing element : " << me << " Repeating element: " << re;
}

void findTwoElement3(int arr[], int n)
{
    int sumN = n * (n + 1) / 2, sumArr = 0;
    long long int sumN2 = n * (n + 1) * (2 * n + 1) / 6, sumArr2 = 0;
    for (int i = 0; i < n; ++i)
    {
        sumArr += arr[i];
        sumArr2 += arr[i] * arr[i];
    }
    int eq1 = abs(sumN - sumArr);
    int eq2 = abs(sumN2 - sumArr2) / eq1;
    int me = (eq1 + eq2) / 2;
    int re = me - eq1;
    cout << "Missing element : " << me << " Repeating element: " << re;
}

void findTwoElement4(int arr[], int n)
{
    int r = 0;

    for (int i = 0; i < n; i++)
    {
        r ^= arr[i] ^ (i + 1);
    }

    cout << "xor = " << r << endl;

    int rsb = r & -r;
    cout << "rsb = " << rsb << endl;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] & rsb == 0)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
        int j = i + 1;

        if (j & rsb == 0)
        {
            x ^= j;
        }
        else
        {
            y ^= j;
        }
    }

    cout << "elements are " << x << " " << y;
}

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    findTwoElement4(arr, 6);
}