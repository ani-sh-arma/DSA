#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            permutations(arr, ds, ans, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

vector<int> nextPermutation(vector<int> arr)
{
    vector<int> originalArr = arr;
    vector<vector<int>> ans = {};
    vector<int> ds;
    int freq[arr.size()] = {0};
    sort(arr.begin(), arr.end());
    permutations(arr, ds, ans, freq);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
        {
            return ans[0];
        }
        if (ans[i] == originalArr)
        {
            return ans[i + 1];
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 2, 1};
    vector<int> ans = nextPermutation(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}