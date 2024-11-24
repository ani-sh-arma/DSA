#include <bits/stdc++.h>
using namespace std;

int countDivisions(vector<int> arr, int divs)
{
    int n = arr.size();
    int cnt = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentSum + arr[i] <= divs)
        {
            currentSum += arr[i];
        }
        else
        {
            cnt++;
            currentSum = arr[i];
        }
    }
    return cnt;
}

int splitArrayLargestSumBrute(vector<int> arr, int k)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    if (k > n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    for (int i = maxi; i < sum; i++)
    {
        if (countDivisions(arr, i) == k)
        {
            return i;
        }
    }
}

int splitArrayLargestSumOptimal(vector<int> arr, int k)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    if (k > n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countDivisions(arr, mid) <= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    cout << splitArrayLargestSumOptimal(arr, m);
    return 0;
}
