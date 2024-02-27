#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        vector<int> resultValues(result.begin() , result.begin()+2); 
        return resultValues;
    }
};

int main() {
    cout << "Hello World!" << endl;

    Solution obj = Solution();
    vector<int> nums = {21, 7, 11, 2};
    int target = 9;

    vector<int> result = obj.twoSum(nums, target);

    if (result.size() == 2) {
        cout << "No solution found." << endl;
    } else {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }

    cout << "Done" << endl;

    return 0;
}
