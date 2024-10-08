#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int j = 0;
    for (auto it : mp)
    {
        arr[j++] = it.first;
    }
    int size = j;
    while (j < n)
    {
        arr[j++] = 0;
    }
    return size;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int size = removeDuplicates(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nSize of new Array : " << size << endl;

    return 0;
}