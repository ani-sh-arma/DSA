#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRepeatingAndMissing(vector<int> a)
{
    pair<int, int> p;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[i] == a[j] && i != j)
            {
                p.first = a[i];
            }

            if (j + 1 != a[i] && j == a.size() - 1)
            {
                p.second = j + 1;
            }
            else
            {
                continue;
            }
        }
    }

    return p;
}

pair<int, int> brute(vector<int> a)
{
    pair<int, int> p = {-1, -1};
    for (int i = 1; i <= a.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (i == a[j])
            {
                cnt++;
            }
            if (cnt == 2)
                p.first = i;
            if (cnt == 0)
                p.second = i;

            if (p.first != -1 && p.second != -1)
            {
                break;
            }
        }
    }

    return p;
}

pair<int, int> better(vector<int> a)
{
    pair<int, int> p = {-1, -1};
    int hash[a.size() + 1] = {0};

    for (int i = 0; i < a.size(); i++)
    {
        hash[a[i]]++;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        if (hash[i] == 2)
            p.first = i;
        if (hash[i] == 0)
            p.second = i;

        if (p.first != -1 && p.second != -1)
        {
            break;
        }
    }

    return p;
}

pair<int, int> optimal1(vector<int> a)
{
    long long S = 0;
    long long Sn = 0;
    long long S2 = 0;
    long long S2n = 0;

    for (long long i = 0; i < a.size(); i++)
    {
        S += a[i];
        Sn += i + 1;
        S2 += a[i] * a[i];
        S2n += (i + 1) * (i + 1);
    }

    long long val1 = S - Sn;
    long long val2 = S2 - S2n;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(long long)x, (long long)y};
}

pair<int, int> optimal2(vector<int> a)
{
    int n = a.size();
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    int bitNo = 0;
    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    // int bitNo = (xr & ~(xr - 1)); // easier way to find bitNumber(Index) through bit manipulation

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & (1 << bitNo)) != 0) // remove "1 << " when using bit manipulation
        {
            one = one ^ a[i];
        }
        else
        {
            zero = zero ^ a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitNo)) != 0) // remove "1 << " when using bit manipulation
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        return {zero, one};
    }
    return {one, zero};
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 6};
    pair<int, int> res = optimal2(arr);
    cout << res.first << " " << res.second;
    return 0;
}
