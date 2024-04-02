#include <bits/stdc++.h>
using namespace std;

void printFrequency(int arr[], int n){
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i]){
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j]){
                count++;
                visited[j] = true;
            }
        }
        
        cout << arr[i] << "\t->\t" << count << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[20] = {0,1,2,5,4,8,75,4,1,2,3,2,1,4,5,2,1,4,5,2};
    printFrequency(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}