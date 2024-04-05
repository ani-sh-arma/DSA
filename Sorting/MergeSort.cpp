#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = 0;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp[i++] = arr[left++];
        }
        else
        {
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
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 5, 6, 8, 5, 96, 2, 54, 952, 58, 475, 54, -9875, -23};
    int count = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, count - 1);

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}