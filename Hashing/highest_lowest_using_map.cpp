#include <bits/stdc++.h>
using namespace std;

void highestLowestFreq(int arr[], int n){
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }

    int maxFreq = 0, minFreq = n;
    int maxElem = 0, minElem = 0;

    for (auto it : ump)
    {
        int count = it.second;
        int element = it.first;
        
        if (count > maxFreq)
        {
            maxFreq = count;
            maxElem = element;
        }
        if (count < minFreq)
        {
            minFreq = count;
            minElem = element;
        }   
    }

    cout << "Element with highest frequency: " << maxElem << endl;
    cout << "Element with lowest frequency: " << minElem << endl;
}


int main(int argc, char const *argv[])
{
    int arr[20] = {0,1,2,5,4,8,75,4,1,2,3,2,1,4,5,2,1,4,5,2};
    highestLowestFreq(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}