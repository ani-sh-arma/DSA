#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> arr, int in, vector<vector<int>> &ans)
{
    if (in >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = in; i < arr.size(); i++)
    {
        swap(arr[in], arr[i]);
        nextPermutation(arr, in + 1, ans);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 1, 2, 3};
    vector<int> copy = arr;
    vector<int> res = {};
    vector<vector<int>> ans = {};
    sort(copy.begin(), copy.end());
    nextPermutation(copy, 0, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
        {
            res = ans[0];
            break;
        }
        if (ans[i] == arr)
        {
            res = ans[i + 1];
            break;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    

    return 0;
}