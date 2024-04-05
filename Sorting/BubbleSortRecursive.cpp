#include<iostream>
using namespace std;

void BubbleSortRecursive(int arr[], int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    BubbleSortRecursive(arr, n-1);
} 

int main(int argc, char const *argv[])
{
    int arr[] = {1,5,6,8,5,96,2,54,952,58,475,54};
    int count = sizeof(arr)/sizeof(arr[0]);
    BubbleSortRecursive(arr, count );

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}