#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr)
{
    int maxLen = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                if (sum == 0)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
    }
    return maxLen;
}

int better(vector<int> arr)
{
    int maxLen = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            sum += arr[j];
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int optimal(vector<int> arr)
{
    int maxLen = INT_MIN;
    unordered_map<int, int> ump;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (ump.find(sum) != ump.end())
        {
            maxLen = max(maxLen, i - ump[sum]);
        }
        else
        {
            ump[sum] = i;
        }
    }
    return maxLen;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    int res = better(arr);
    cout << res;
    return 0;
}
