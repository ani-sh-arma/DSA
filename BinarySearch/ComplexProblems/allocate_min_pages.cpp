#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> arr, int pages)
{
    int n = arr.size();
    int cnt = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentSum + arr[i] <= pages)
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

int allocateMinPagesBrute(vector<int> arr, int m)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    if (m > n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    for (int i = maxi; i < sum; i++)
    {
        if (countStudents(arr, i) == m)
        {
            return i;
        }
    }
}

int allocateMinPagesOptimal(vector<int> arr, int m)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    if (m > n)
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
        if (countStudents(arr, mid) <= m)
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
    cout << allocateMinPagesOptimal(arr, m);
    return 0;
}
