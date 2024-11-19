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
            }else
            {
                cnt = 0;
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

int main(int argc, char const *argv[])
{
    vector<int> days = {1, 10, 1, 10, 2};
    int m = 2;
    int k = 2;
    int ans = minDaysToMakeMBouquets(days, m, k);
    cout << ans << endl;
    return 0;
}
