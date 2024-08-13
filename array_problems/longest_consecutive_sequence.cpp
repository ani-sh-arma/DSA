#include <bits/stdc++.h>
using namespace std;

int bruteForceApproach(vector<int> arr)
{
    int maxCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            for (int k = 0; k < arr.size(); k++)
            {
                if (arr[i] + j == arr[k])
                {
                    count++;
                }
            }
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int betterApproach(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    sort(arr.begin(), arr.end());
    int count = 0;
    int lastSmaller = INT_MIN;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int optimalApproach(vector<int> arr)
{
    int n = arr.size();
    if (n <= 0)
        return 0;

    unordered_set<int> ust;
    for (int i = 0; i < arr.size(); i++)
    {
        ust.insert(arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {100, 200, 1, 3, 2, 4, 5, 6, 9, 8, 2, 8, 7, 6, 544, 58, 5, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115};
    int res = betterApproach(arr);
    cout << res;
    return 0;
}
