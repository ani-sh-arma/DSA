#include <bits/stdc++.h>
using namespace std;

int binarySearchInRotatedArrayOfDistinctValues(vector<int> a, int x)
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

bool binarySearchInRotatedArrayOfDuplicateValues(vector<int> a, int x)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return true;
        }

        if (a[low] == a[mid] && a[mid] == a[high])
        {
            low++;
            high--;
            continue;
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
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 5, 6, 6, 7, 0, 1, 1, 2, 3, 4};
    int x = 0;
    int ans = binarySearchInRotatedArrayOfDistinctValues(arr, x);
    cout << "Answer : " << ans << "\n";
    cout << "Bool Answer : " << binarySearchInRotatedArrayOfDuplicateValues(arr, x) << "\n";
    return 0;
}
