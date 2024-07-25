#include <bits/stdc++.h>
using namespace std;

// Works for all numbers { -, 0, + }  with time complexity of O(Nlog(N)) and space complexity O(N) due to map.
int longestSubarrayHashed(vector<int> arr, long long k)
{
    map<long long, int> hashmap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (hashmap.find(rem) != hashmap.end())
        {
            int len = i - hashmap[rem];
            maxLen = max(maxLen, len);
        }
        if (hashmap.find(sum) == hashmap.end())
        {
            hashmap[sum] = i;
        }
    }
    return maxLen;
}

// Works only for values 0 and positives but has a worst case time complexity O(2N) and space complexity O(1)
int longestSubarrayOptimal(vector<int> arr, long long k)
{
    int maxLen = 0;
    long long sum = arr[0];
    int left = 0, right = 0;
    int n = arr.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }

    return maxLen;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 0, 0, 0, 0, 1, 1, 1, -1, 2, 2};
    int ans = longestSubarrayOptimal(arr, 7);
    cout << ans << " ";

    return 0;
}