#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            if (arr[mid] == target)
            {
                ans = mid;
            }
            else
            {
                ans = -1;
            }
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int ans = firstOccurence(arr, 4);
    cout << "Iterative Binary Search : " << ans << endl;
    return 0;
}
