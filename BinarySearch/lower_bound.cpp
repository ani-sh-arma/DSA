#include <bits/stdc++.h>
using namespace std;

int itrLowerBound(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target)
        {
            return i;
        }
    }
    return arr.size();
}

int lowerBound(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int recursiveLowerBound(vector<int> arr, int low, int high, int target)
{
    if (low > high)
    {
        return arr.size();
    }
    int mid = (low + high) / 2;
    if (arr[mid] < target)
        return recursiveLowerBound(arr, mid + 1, high, target);
    else
    {
        int tempAns = recursiveLowerBound(arr, low, mid - 1, target);
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
    int target = 0;
    cout << "LS Lower Bound : " << itrLowerBound(arr, target) << endl;
    cout << "IBS Lower Bound : " << lowerBound(arr, target) << endl;
    cout << "RBS Lower Bound : " << recursiveLowerBound(arr, 0, arr.size() - 1, target) << endl;
    return 0;
}
