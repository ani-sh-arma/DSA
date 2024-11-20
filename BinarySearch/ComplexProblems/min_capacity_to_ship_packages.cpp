#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> weights, int c)
{
    int n = weights.size();
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + weights[i] <= c)
        {
            sum += weights[i];
        }
        else
        {
            sum = weights[i];
            cnt++;
            if (i == n - 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int minCapacityToShipPackages(vector<int> weights, int d)
{
    int n = weights.size();
    int maxVal = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxVal = max(maxVal, weights[i]);
    }
    for (int i = maxVal; i <= sum; i++)
    {
        int days = findDays(weights, i);
        if (days <= d)
        {
            return i;
        }
    }
    return -1;
}

int minCapacityToShipPackagesOptimal(vector<int> weights, int d)
{
    int n = weights.size();
    int maxVal = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxVal = max(maxVal, weights[i]);
    }

    int low = maxVal, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int days = findDays(weights, mid);
        if (days <= d)
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
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    cout << minCapacityToShipPackagesOptimal(weights, d);
    return 0;
}
