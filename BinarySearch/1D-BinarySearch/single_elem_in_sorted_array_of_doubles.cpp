#include <bits/stdc++.h>
using namespace std;

bool isOdd(int num)
{
    if (num % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int singleAppearingElement(vector<int> arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        if (arr[mid] == arr[mid + 1] )
        {
            if (isOdd(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (isOdd(mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
    cout << singleAppearingElement(arr);
    return 0;
}
