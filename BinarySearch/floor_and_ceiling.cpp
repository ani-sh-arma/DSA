#include <bits/stdc++.h>
using namespace std;

pair<int, int> iterativeBinarySearch(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return {arr[mid], arr[mid]};
        }
        else if (arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return {-1, -1};
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << "Iterative : " << iterativeBinarySearch(arr, 6).first << " " << iterativeBinarySearch(arr, 6).second << endl;
    return 0;
}
