#include <bits/stdc++.h>
using namespace std;

int smallestValueInRotatedArray(vector<int> a)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1])
        {
            return a[mid];
        }
        else if (a[mid] < a[mid - 1])
        {
            if (a[mid] < a[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (a[mid] < a[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
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
    int ans = findMin(arr);
    cout << "Answer : " << ans << "\n";
    return 0;
}
