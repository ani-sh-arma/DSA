#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 8, 5, 6, 4, 6, 56, 56, 6, 595, 6, 2, 59, 56, 26, 59, 56, 2, 65, 56, 2, -56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
        
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
        
    }

    cout << "Largest Element : " << largest << endl;
    cout << "Second Largest Element : " << secondLargest << endl;
    cout << "Smallest Element : " << smallest << endl;
    cout << "Second Smallest Element : " << secondSmallest << endl;
    return 0;
}