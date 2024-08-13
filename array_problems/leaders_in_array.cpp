#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> arr)
{
    int currentSmallest = INT_MAX;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] < currentSmallest)
        {
            currentSmallest = arr[i];
            ans.push_back(currentSmallest);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 5, 4, 6, 3, 1, 8, 9, 7, 5};
    vector<int> ans = findLeaders(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
