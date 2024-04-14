#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateLeftOrRight(int arr[], int n, int k, bool isLeft)
{
    if (isLeft)
    {
        reverse(arr, k, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, 0, n - 1);
    }
    else
    {
        reverse(arr, n - k, n - 1);
        reverse(arr, 0, n - 1 - k);
        reverse(arr, 0, n - 1);
    }
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
    rotateLeftOrRight(arr, n, 4, true);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}