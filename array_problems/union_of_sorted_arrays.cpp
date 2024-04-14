#include <bits/stdc++.h>
using namespace std;
// Works for sorted arrays only
// Time Complexity : O(n+m)

void unionOfArrays(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> result;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (result.size() == 0 || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n)
    {
        if (result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if (result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9};
    int arr2[] = {1, 2, 5, 6, 7, 8, 9, 10, 11, 12, 23, 24};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    unionOfArrays(arr1, arr2, n, m);
    return 0;
}