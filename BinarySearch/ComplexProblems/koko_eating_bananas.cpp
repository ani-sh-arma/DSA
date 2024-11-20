

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &piles)
{
    int max = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        max = max > piles[i] ? max : piles[i];
    }
    return max;
}

int minEatingSpeedBrute(vector<int> &piles, int h)
{
    int n = piles.size();

    for (int i = 1; i <= findMax(piles); i++)
    {
        int hours = 0;
        for (int j = 0; j < n; j++)
        {
            hours += ceil(double(piles[j]) / double(i));
        }
        if (hours <= h)
        {
            return i;
        }
    }

    return -1;
}

int minEatingSpeedOptimal(vector<int> &piles, int h)
{
    int n = piles.size();

    int low = 1, high = findMax(piles);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int hours = 0;
        for (int j = 0; j < n; j++)
        {
            hours += ceil(double(piles[j]) / double(mid));
        }
        if (hours <= h)
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
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;
    cout << minEatingSpeedOptimal(piles, h);
    return 0;
}
