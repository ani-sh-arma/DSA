#include <bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return -1;
}

int missingNumberXOR(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int missingNumberOptimal(int arr[], int n)
{
    int sumN = 0;
    int sumArr = 0;
    for (int i = 0; i < n - 1; i++) // n-1 because size of the array is n-1 not n.
    {
        sumN = sumN + (i + 1);
        sumArr = sumArr + arr[i];
    }
    sumN += n;
    return sumN - sumArr;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 9;
    int ans = missingNumberOptimal(arr1, n);
    cout << "Missing number is: " << ans << endl;
    return 0;
}