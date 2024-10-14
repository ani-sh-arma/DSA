#include <bits/stdc++.h>
using namespace std;

int countOccurenceItr(vector<int> arr, int x)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            cnt++;
        }
    }
    return cnt;
}

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

int lastOccurence(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            if (arr[mid] == target)
            {
                ans = mid;
            }
            else
            {
                ans = -1;
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 2, 4, 4, 4, 4, 10};
    int x = 4;
    int ans = countOccurenceItr(arr, x);
    int firstOcc = firstOccurence(arr, x);
    int lastOcc = lastOccurence(arr, x);
    if (firstOcc == -1)
    {
        firstOcc = 0;
    }

    cout << "BS Answer : " << lastOcc - firstOcc + 1 << endl;
    cout << "Iterative : " << ans << endl;
    return 0;
}
