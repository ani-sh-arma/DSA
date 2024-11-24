#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> arr, int painters)
{
    int n = arr.size();
    int cnt = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentSum + arr[i] <= painters)
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

int paintersPartitianBrute(vector<int> arr, int k)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }
    for (int i = maxi; i < sum; i++)
    {
        if (countPainters(arr, i) == k)
        {
            return i;
        }
    }
}

int paintersPartitianOptimal(vector<int> arr, int k)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }
    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countPainters(arr, mid) <= k)
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
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << paintersPartitianOptimal(arr, k);
    return 0;
}
