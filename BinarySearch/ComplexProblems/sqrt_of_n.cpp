#include <bits/stdc++.h>
using namespace std;

int bruteForce(int n)
{
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (i * i > n)
        {
            break;
        }
        ans = i;
    }
    return ans;
}

int optimal(long long n)
{
    long long low = 1, high = n;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;

        if (val <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main(int argc, char const *argv[])
{
    long long n = 1500000341;

    cout << optimal(n) << " Actual Answer is : " << sqrt(n) << endl;

    return 0;
}
