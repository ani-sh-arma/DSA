#include <bits/stdc++.h>
using namespace std;

int bruteMaxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    long long maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int betterMaxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    long long maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int optimalMaxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    long long maxSum = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

vector<int> SubarrayOfMaxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    long long maxSum = INT_MIN;
    long long sum = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            end = i;
        }

        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
            start = i;
            end = i;
        }
    }

    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i >= start && i <= end)
            ans.push_back(arr[i]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, 2, -5, 4};
    vector<int> ans = SubarrayOfMaxSubarraySum(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
