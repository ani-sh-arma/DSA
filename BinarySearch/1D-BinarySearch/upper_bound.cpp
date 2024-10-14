#include <bits/stdc++.h>
using namespace std;

int itrUpperBound(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > target)
        {
            return i;
        }
    }
    return arr.size();
}

int upperBound(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
}

int recursiveUpperBound(vector<int> arr, int low, int high, int target)
{
    if (low > high)
    {
        return arr.size();
    }
    int mid = (low + high) / 2;
    if (arr[mid] <= target)
        return recursiveUpperBound(arr, mid + 1, high, target);
    else
    {
        int tempAns = recursiveUpperBound(arr, low, mid - 1, target);
        if (tempAns == arr.size())
        {
            return mid;
        }
        return tempAns;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;
    cout << "LS Lower Bound : " << itrUpperBound(arr, target) << endl;
    cout << "IBS Lower Bound : " << upperBound(arr, target) << endl;
    cout << "RBS Lower Bound : " << recursiveUpperBound(arr, 0, arr.size() - 1, target) << endl;
    return 0;
}
