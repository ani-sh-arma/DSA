#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
} 

int main(int argc, char const *argv[])
{
    int arr[] = {1,5,6,8,5,96,2,54,952,58,475,54,-9875,-23};
    int count = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, count );

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}