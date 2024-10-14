#include <bits/stdc++.h>
using namespace std;

int iterativeBinarySearch(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return -1;
};

int recursiveBinarySearch(vector<int> arr, int start, int end, int target)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return -1;
    }

    if (arr[mid] == target)
    {
        return mid;
    }

    else if (arr[mid] > target)
    {
        return recursiveBinarySearch(arr, start, mid - 1, target);
    }
    else
    {
        return recursiveBinarySearch(arr, mid + 1, end, target);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << "Iterative : " << iterativeBinarySearch(arr, 6) << endl;
    cout << "Recursive : " << recursiveBinarySearch(arr, 0, arr.size() - 1, 17) << endl;
    return 0;
}
