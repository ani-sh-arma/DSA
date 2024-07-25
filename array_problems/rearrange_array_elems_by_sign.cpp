#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayBySign(vector<int> arr)
{
    vector<int> pos, neg, res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    // Smart way of doing this:
    for (int i = 0; i < (arr.size()) / 2; i++)
    {
        res[i * 2] = pos[i];
        res[i * 2 + 1] = neg[i];
    }

    // Stupid way of doing this:
    // int negCount = 0;
    // int posCount = 0;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if ((i + 1) % 2 == 0)
    //     {
    //         res.push_back(neg[negCount++]);
    //     }
    //     else
    //     {
    //         res.push_back(pos[posCount++]);
    //     }
    // }

    return res;
}

vector<int> optimalApproach(vector<int> arr)
{
    int n = arr.size();
    int posIndex = 0, negIndex = 1;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> ans = optimalApproach(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
