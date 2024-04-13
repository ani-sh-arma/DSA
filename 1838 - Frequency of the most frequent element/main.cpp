// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    unordered_map<int, int> ump;

    for (int i = 0; i < nums.size(); i++)
    {
        ump[nums[i]]++;
    }

    int maxFreq = 0;
    int maxElem = 0;

    for (auto it : ump)
    {
        int count = it.second;
        int element = it.first;
        
        if (count > maxFreq)
        {
            maxFreq = count;
            maxElem = element;
        }
    }

    for (auto it : nums)
    {
        if (maxElem - it <= k && k != 0 )
        {
            while (it != maxElem)
            {
                it++;
                k--;
                maxFreq++;
            }
        }
    }
    
    return maxFreq;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2,3};
    int result = maxFrequency(nums, 4);
    cout << result << endl;
    return 0;
}
