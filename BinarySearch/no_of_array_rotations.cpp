#include <bits/stdc++.h>
using namespace std;

int noOfTimesRotated(vector<int> a)
{
    int count = 0;
    while (a[0] > a[a.size() - 1])
    {
        a.push_back(a.front());
        a.erase(a.begin());
        count++;
    }
    return count;
}

int findMin(vector<int> nums)
{

    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }

        if (nums[low] < nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 5, 6, 7, -1, 0, 1, 2, 3};
    int ans = noOfTimesRotated(arr);
    cout << "Answer : " << ans << "\n";
    return 0;
}
