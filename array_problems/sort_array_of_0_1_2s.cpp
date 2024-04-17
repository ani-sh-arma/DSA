#include <bits/stdc++.h>
using namespace std;

// Time complexity O(2N) and Space Complexity O(1)
vector<int> sortByCount(vector<int> &arr)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if(arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (i < count0)
        {
            arr[i] = 0;
        }
        else if (i >= count0 && i < count0 + count1)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 2;
        }
    }
}

// 3 Pointer method Time Complexity O(N) and Space Complexity O(1)
vector<int> sort3Pointer(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size()-1;
    while (mid<=high)
    {    
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1 )
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0,2,0,1,2,0,1,2,0,1,0,1,1,0,2,1,2,0,0,1,0,0,1,0,2,0,1};
    // Approach 1 Time Complexity O(Nlog(N)) Space Complexity O(1)
    // sort(arr.begin(), arr.end()); 
    sort3Pointer(arr);
    for (auto &&i : arr)
    {
        cout << i << " "; 
    }
    cout << endl;
    return 0;
}