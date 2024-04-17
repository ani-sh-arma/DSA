#include <bits/stdc++.h>
using namespace std;

// Majority element is an element that occurs more than N/2 times

// Time complexity O(Nlog(N)) and Space Complexity O(1)
int countByHashing(vector<int> &arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (auto &&it : mp)
    {
        if (it.second > arr.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// Moore's Voting Algorithm || Time Complexity O(N) Space Complexity O(1)
int mooresAlgorithm(vector<int> &arr)
{
    int element;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (element == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int elemCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            elemCount++;
        }
    }
    if (elemCount > (arr.size() / 2))
    {
        return element;
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 2, 0, 1, 2, 0, 1, 2, 0, 1, 0, 1, 1, 0, 2, 1, 2, 0, 0, 1, 0, 0, 1, 0, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int result = mooresAlgorithm(arr);

    cout << "Majority Element: " << result << endl;
    return 0;
}