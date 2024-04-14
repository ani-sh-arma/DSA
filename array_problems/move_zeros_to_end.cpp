#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd(int arr[], int n)
{
    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j++] = arr[i];
            count++;
            continue;
        }
    }
    for (int i = count; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 0, 0, 0, 15, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    moveZerosToEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}