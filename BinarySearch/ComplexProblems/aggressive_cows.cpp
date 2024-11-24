#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> arr, int k, int dist)
{
    int n = arr.size();
    int last = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= dist)
        {
            cnt++;
            last = arr[i];
        }
        if (cnt >= k)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCowsBrute(vector<int> arr, int k)
{
    int n = arr.size();
    int mini = 1, maxi = arr[n - 1] - arr[0];
    int maxDist = INT_MIN;

    for (int i = mini; i <= maxi; i++)
    {
        if (canWePlace(arr, k, i))
        {
            maxDist = max(maxDist, i);
        }
    }
    return maxDist;
}

int aggressiveCowsOptimal(vector<int> arr, int k)
{
    int n = arr.size();
        int mini = 1, maxi = arr[n - 1] - arr[0];

    while (mini <= maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        if (canWePlace(arr, k, mid))
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid - 1;
        }
    }
    return maxi;
}

int main(int argc, char const *argv[])
{
    // vector<int> arr = {4, 2, 1, 3, 6};
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    sort(arr.begin(), arr.end());
    int k = 4;
    cout << aggressiveCowsOptimal(arr, k);

    return 0;
}
