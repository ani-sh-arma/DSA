#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumsToK(int arr[], int n, int target)
{
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                int count = j - i + 1;
                if (count >= maxCount)
                {
                    maxCount = count;
                }
                else
                {
                    return maxCount;
                }   
            }
        }
    }
    return maxCount;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = longestSubarraySumsToK(arr, n, 7);
    cout << ans << " ";
    
    return 0;
}