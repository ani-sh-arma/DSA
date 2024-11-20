#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> arr, int limit)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    for (int i = 1; i <= maxi; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += ceil(double(arr[j]) / double(i));
        }

        if (sum <= limit)
        {
            return i;
        }
    }
    return -1;
}

int smallestDivisorOptimal(vector<int> arr, int limit)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int low = 1;
    int high = maxi;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil(double(arr[i]) / double(mid));
        }
        if (sum <= limit)
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int limit = 15;
    cout << smallestDivisorOptimal(arr, limit);
    return 0;
}
