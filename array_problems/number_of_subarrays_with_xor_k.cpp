#include <bits/stdc++.h>
using namespace std;

int noOfSubarraysWithXORK(vector<int> arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int XOR = 0;
            for (int k = i; k <= j; k++)
            {
                XOR ^= arr[k];
            }
            if (XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

int better(vector<int> arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int XOR = 0;
        for (int j = i; j < arr.size(); j++)
        {
            XOR ^= arr[j];
            if (XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

int optimal(vector<int> arr, int k)
{
    int count = 0;
    unordered_map<int, int> ump;
    int XOR = 0;
    ump[XOR]++;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR ^= arr[i];
        int x = XOR ^ k;
        count += ump[x];
        ump[XOR]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5, 6, 7, 8, 9};
    int res = optimal(arr, 5);
    cout << res;
    return 0;
}
