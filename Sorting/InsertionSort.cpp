#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] >= arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
} 

int main(int argc, char const *argv[])
{
    int arr[] = {1,5,6,8,5,96,2,54,952,58,475,54,-9875,-23};
    int count = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, count);

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}