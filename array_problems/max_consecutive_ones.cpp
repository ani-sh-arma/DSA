#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int arr[], int n)
{
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else
        {
            count = 0;
        }
        
        
    }
    return maxCount;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,0,0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = maxConsecutiveOnes(arr, n);
    cout << "Maximum consecutive 1s are : " << ans << endl;
    return 0;
}