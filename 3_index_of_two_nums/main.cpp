#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution obj = Solution();
    vector<int> nums = {-12, 21, 7, 11, 2};
    int target = 9;

    vector<int> result = obj.twoSum(nums, target);

    if (result.size() == 0)
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Indices: " << result[0] << " " << result[1] << result[2] << result[3] << endl;
    }

    cout << "Done" << endl;

    return 0;
}
