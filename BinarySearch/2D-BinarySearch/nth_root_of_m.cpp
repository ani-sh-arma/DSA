#include <bits/stdc++.h>
using namespace std;

int bruteForce(int n, int m)
{
    // int ans = 1;
    for (int i = 1; i <= m / 2; i++)
    {
        cout << "For1\n";
        int temp = 1;
        for (int j = 1; j <= n; j++)
        {
            cout << "For2\n";
            temp *= i;
        }
        if (temp == m)
        {
            return i;
        }

        if (temp > m)
        {
            break;
        }
    }

    return -1;
}

int optimal(int n, int m)
{
    int low = 1, high = m / 2;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        int temp = 1;
        for (int i = 1; i <= n; i++)
        {
            temp *= mid;
            if (temp > m)
            {
                high = mid - 1;
                break;
            }
        }
        if (temp == m)
        {
            return mid;
        }
        if (temp > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int n = 4, m = 4096;
    cout << optimal(n, m);
    return 0;
}
