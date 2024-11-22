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

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 7, 9, 10};
    int k = 6;
    cout << findKthMissingPositive(arr, k);

    return 0;
}
