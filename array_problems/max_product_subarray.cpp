#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(vector<int> arr)
{
    int n = arr.size();
    int maxProd = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        int prod = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            prod *= arr[j];
        }
        maxProd = max(maxProd, prod);
    }

    return maxProd;
}

int optimal(vector<int> arr)
{
    int n = arr.size();
    int maxProd = INT_MIN;
    int pre = 1, suf = 1;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre *= arr[i];
        suf *= arr[n - i - 1];
        maxProd = max(maxProd, max(pre, suf));
    }
    return maxProd;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << optimal(arr);
    return 0;
}
