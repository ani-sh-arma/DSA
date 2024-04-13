#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int n)
{
    // TODO: Doesn't work yet.
    int last = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i+1])
        {
            int j = i;
            while (arr[j] <= arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }   
        }   
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
    removeDuplicates(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}