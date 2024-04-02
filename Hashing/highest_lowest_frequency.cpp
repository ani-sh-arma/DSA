#include <bits/stdc++.h>
using namespace std;

pair<int, int> largestAndSmallest(int arr[], int size) {
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "Highest Frequency: " << largest << endl;
    cout << "Lowest Frequency: " << smallest << endl;

    return make_pair(largest, smallest);
}

void getFrequencyHash(int arr[], int n, int largest){
    int hash[largest+1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    pair<int, int> result = largestAndSmallest(hash, largest + 1);

    for (int i = 0; i < largest + 1; i++)
    {
        if(hash[i] == result.first){
            cout << i << " occurs most frequently " << result.first << " times" << endl;
        }
        if(hash[i] == result.second){
            cout << i << " occurs least frequently " << result.second << " times" << endl;
            return;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int arr[20] = {0,1,2,5,4,8,75,4,1,2,3,2,1,4,5,2,1,4,5,2};
    getFrequencyHash(arr, sizeof(arr)/sizeof(arr[0]), 75);
    return 0;
}