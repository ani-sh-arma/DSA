#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[++i] = arr[j];
        }
    }

    return i + 1;
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