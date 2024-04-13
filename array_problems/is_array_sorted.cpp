#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "In false";
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 8, 5, 6, 4, 6, 56, 56, 6, 595, 6, 2, 59, 56, 26, 59, 56, 2, 65, 56, 2, -56};
    int arrSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Is Sorted : " << isSorted(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    cout << "Is Sorted : " << isSorted(arrSorted, sizeof(arrSorted) / sizeof(arrSorted[0])) << endl;
    return 0;
}