#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n = 1500000341;
    long long ans = 0;

    for (long long i = 0; i < n; i++)
    {
        if (i * i > n)
        {
            break;
        }
        ans = i;
    }

    cout << ans << " Actual Answer is : " << sqrt(n) << endl;

    return 0;
}
