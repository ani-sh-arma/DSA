#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &arr)
{
    map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > arr.size() / 3)
        {
            res.push_back(it.first);
        }
    }
    return res;
}

vector<int> majorityElementBetter(vector<int> &arr)
{
    map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == (arr.size() / 3) + 1)
        {
            res.push_back(arr[i]);
        }
    }
    return res;
}

vector<int> majorityElementOptimal(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && ele2 != arr[i])
        {
            ele1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0 && ele1 != arr[i])
        {
            ele2 = arr[i];
            count2 = 1;
        }
        else if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
        else
            count1--, count2--;
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        if (arr[i] == ele2)
        {
            count2++;
        }
    }

    if (count1 > n / 3)
        res.push_back(ele1);
    if (count2 > n / 3)
        res.push_back(ele2);

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 2};

    vector<int> res = majorityElementOptimal(arr);
    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}