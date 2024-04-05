#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
} 

int main(int argc, char const *argv[])
{
    int arr[] = {1,5,6,8,5,96,2,54,952,58,475,54,-9875,-23};
    int count = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, count );

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}