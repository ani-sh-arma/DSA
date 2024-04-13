#include <iostream>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (pivot <= arr[j] && j >= low + 1) // make pivot >= arr[j] for Descending Order
        {
            j--;
        }
        while (pivot >= arr[i] && i <= high - 1) // make pivot <= arr[j] for Descending Order
        {
            i++;
        }
        if (i < j)
        {
            swap(arr[i],arr[j]);
        }        
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 5, 6, 8, 5, 96, 2, 54, 952, 58, 475, 54, -9875, -23};
    int count = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, count - 1);

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}