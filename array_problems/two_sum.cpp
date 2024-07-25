#include <bits/stdc++.h>
using namespace std;

// Time complexity O(N^2)
bool twoSum(vector<int> &nums, int target)
{
    bool exists = false;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                exists = true;
            }
        }
    }
    return exists;
}

// Time complexity O(N*log(N)) for map can be optimized to O(N) using unordered_map but worst case will be O(N^2)
vector<int> twoSumHashed(vector<int> &nums, int target)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// Optimal approach two pointer method with Time Complexity O(N) + O(NlogN) for sorting and Space Complexity O(1)
// Requires a sorted array to work and sorts the array if not sorted returns the indices according to sorted array
vector<int> twoSumOptimal(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum > target)
            right--;
        else if (sum == target)
            return {left, right};
        else
            left++;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 21};
    int target = 23;

    vector<int> result = twoSumOptimal(nums, target);
    cout << "Indices: " << result[0] << " " << result[1] << endl;
    // cout << result;
    return 0;
}