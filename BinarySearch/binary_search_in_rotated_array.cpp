#include <bits/stdc++.h>
using namespace std;

int binarySearchInRotatedArray(vector<int> a, int x)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] >= a[low])
        {
            if (a[low] <= x && x <= a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (a[mid] <= x && x <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int x = 2;
    int ans = binarySearchInRotatedArray(arr, x);
    cout << "Answer : " << ans;
    return 0;
}
