#include <bits/stdc++.h>
using namespace std;

int usingHashing(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

int usingXOR(int arr[], int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = usingXOR(arr, n);
    cout << "Number that appears once is : " << ans << endl;
    return 0;
}