#include <bits/stdc++.h>
using namespace std;

int findKthMissingPositive(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> newArr;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < max; i++)
    {
        if (find(arr.begin(), arr.end(), i) == arr.end())
        {
            newArr.push_back(i);
        }
    }

    return newArr[k];
}

int findKthMissingPositiveBetter(vector<int> arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

int findKthMissingPositiveOptimal(vector<int> arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low + k;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 7, 9, 10};
    int k = 5;
    cout << findKthMissingPositiveOptimal(arr, k);

    return 0;
}
