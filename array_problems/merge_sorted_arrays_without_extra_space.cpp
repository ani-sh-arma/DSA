#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> arr;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr.push_back(arr1[i++]);
        else
            arr.push_back(arr2[j++]);
    }

    while (i < n)
    {
        arr.push_back(arr1[i++]);
    }
    while (j < m)
    {
        arr.push_back(arr2[j++]);
    }
    return arr;
}

void better(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
        else
            break;
        i--;
        j++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void optimal(int arr1[], int arr2[], int n, int m)
{
    int gap = nextGap(n + m); // Initial gap

    // Start with the largest gap and reduce it gradually
    while (gap > 0)
    {
        int i = 0, j = gap + i;

        // Perform comparison and swap elements according to gap
        while (j < n + m)
        {
            // Case 1: Both pointers in arr1
            if (i < n && j < n)
            {
                if (arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
            }
            // Case 2: Pointer i in arr1 and pointer j in arr2
            else if (i < n && j >= n)
            {
                if (arr1[i] > arr2[j - n])
                {
                    swap(arr1[i], arr2[j - n]);
                }
            }
            // Case 3: Both pointers in arr2
            else if (i >= n)
            {
                if (arr2[i - n] > arr2[j - n])
                {
                    swap(arr2[i - n], arr2[j - n]);
                }
            }
            i++;
            j++;
        }
        gap = nextGap(gap); // Reduce the gap
    }
}

int main()
{
    int arr1[4] = {0, 3, 5, 7};
    int arr2[3] = {1, 4, 8};
    // vector<int> arr = bruteForce(arr1, arr2, 4, 3);
    // better(arr1, arr2, 4, 3);
    optimal(arr1, arr2, 4, 3);

    for (int i = 0; i < 4; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}
