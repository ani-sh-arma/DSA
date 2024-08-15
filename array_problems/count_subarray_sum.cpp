#include <bits/stdc++.h>
using namespace std;

int countSubarraySum(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

int optimalApproach(vector<int> arr, int k)
{
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        if (mp.find(sum - k) != mp.end())
            count = count + mp[sum - k];
        mp[sum]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 4, 20, 3, 10, 5, 3, 2};
    cout << optimalApproach(arr, 5) << endl;

    return 0;
}
