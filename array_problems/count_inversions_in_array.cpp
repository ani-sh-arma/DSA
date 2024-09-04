#include <bits/stdc++.h>
using namespace std;

int countInversions(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
                cnt++;
        }
    }
    return cnt;
}

int merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = 0;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high)
    {

        if (arr[left] <= arr[right])
        {
            temp[i++] = arr[left++];
        }
        else
        {
            cnt += (mid - left + 1);
            temp[i++] = arr[right++];
        }
    }
    while (left <= mid)
    {
        temp[i++] = arr[left++];
    }
    while (right <= high)
    {
        temp[i++] = arr[right++];
    }

    for (int j = 0; j < i; j++)
    {
        arr[low + j] = temp[j];
    }

    return cnt;
}

int optimal(int a[], int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = low + (high - low) / 2;
    cnt += optimal(a, low, mid);
    cnt += optimal(a, mid + 1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 4, 3, 2, 1};
    cout << optimal(arr, 0, 4);
    return 0;
}
