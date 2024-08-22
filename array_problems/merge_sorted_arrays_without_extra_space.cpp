#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr1[i], arr2[j]);
            i++;
            j++;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main(int argc, char const *argv[])
{
    int arr1[4] = {0, 3, 5, 7};
    int arr2[3] = {1, 4, 8};
    merge(arr1, arr2, 4, 3);

    for (int i = 0; i < 4; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
