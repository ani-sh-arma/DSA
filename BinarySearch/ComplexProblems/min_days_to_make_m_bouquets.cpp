#include <bits/stdc++.h>
using namespace std;

int minDaysToMakeMBouquets(vector<int> days, int m, int k)
{
    int n = days.size();
    int currentAns = INT_MAX;

    if (m * k > n)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int bouquets = 0;
        for (int j = 0; j < n; j++)
        {
            if (cnt == k)
            {
                bouquets++;
                cnt = 0;
            }

            if (days[j] <= days[i])
            {
                cnt++;
            }
        }
        if (bouquets == m)
        {
            currentAns = min(currentAns, days[i]);
        }
    }

    if (currentAns != INT_MAX)
    {
        return currentAns;
    }

    return -1;
}

int minDaysToMakeMBouquetsOptimal(vector<int> days, int m, int k)
{
    int n = days.size();
    int mini = INT_MAX, maxi = INT_MIN;

    if (m * k > n)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, days[i]);
        maxi = max(maxi, days[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        int bouquets = 0;
        for (int j = 0; j < n; j++)
        {

            if (days[j] <= mid)
            {
                cnt++;
                if (cnt == k)
                {
                    bouquets++;
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        if (bouquets >= m)
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
    vector<int> days = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2;
    int k = 3;
    int ans = minDaysToMakeMBouquetsOptimal(days, m, k);
    cout << ans << endl;
    return 0;
}
