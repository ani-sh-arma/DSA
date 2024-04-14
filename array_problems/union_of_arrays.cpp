#include <bits/stdc++.h>
using namespace std;
// Works for sorted and unsorted arrays
// Time Complexity : O((n+m)*log(n+m))

int unionOfArrays(int arr1[],int arr2[], int n, int m)
{
    map<int,int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        mp[arr2[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9,5,6,3,2};
    int arr2[] = {1, 2,5, 6, 7, 8, 9,5,6,3,2,10,11,12,56,23,24};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    unionOfArrays(arr1, arr2, n, m);
    return 0;
}