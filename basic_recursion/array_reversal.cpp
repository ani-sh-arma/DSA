#include <iostream>
using namespace std;

void reversal(int arr[], int start, int end)
{
    if (start < end)
    {
        swap(arr[start], arr[end]);
        reversal(arr, start + 1, end - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    reversal(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
