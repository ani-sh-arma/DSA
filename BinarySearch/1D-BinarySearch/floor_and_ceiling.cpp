#include <bits/stdc++.h>
using namespace std;

pair<int, int> floorAndCeil(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return {arr[mid], arr[mid]};
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (high == -1 || low == -1)
    {
        return {-1, -1};
    }
    return {arr[high], arr[low]};
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    pair<int, int> ans = floorAndCeil(arr, 3);
    cout << "Iterative Binary Search : " << ans.first << " " << ans.second << endl;
    return 0;
}
