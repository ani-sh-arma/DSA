#include <bits/stdc++.h>
using namespace std;

int noOfTimesRotated(vector<int> a)
{
    int count = 1;
    while (a[count - 1] < a[count])
    {
        count++;
    }
    return count;
}

int noOfRotations(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }

        if (nums[low] < nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 5, 6, 7, -1, 0, 1, 2, 3};
    int ans = noOfRotations(arr);
    cout << "Answer : " << ans << "\n";
    return 0;
}