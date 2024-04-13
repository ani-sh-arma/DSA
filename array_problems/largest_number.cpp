#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 8, 5, 6, 4, 6, 56, 56, 6, 595, 6, 2, 59, 56, 26, 59, 56, 2, 65, 56, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = 0;
    int secondLargest = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == largest)
            continue;

        if (arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    cout << "Largest Element : " << largest << endl;
    cout << "Second Largest Element : " << secondLargest << endl;
    return 0;
}