#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    long long val = 1;
    for (int i = 0; i < r; i++)
    {
        val = val * (n - i);
        val = val / (i + 1);
    }
    return val;
}

void printRandCthValue(int r, int c)
{
    int val = nCr(r - 1, c - 1);
    cout << val << endl;
}

// Naive Approach Time Complexity O(n^2)
void printNthRow(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nCr(n - 1, i) << " ";
    }
    cout << endl;
}

// Optimal Approach Time Complexity O(n)
void printNthRowOptimal(int n)
{
    long long val = 1;
    cout << val << " ";

    for (int i = 1; i < n; i++)
    {
        val = val * (n - i);
        val = val / i;
        cout << val << " ";
    }

    cout << endl;
}

// Naive Approach Time Complexity O(n^3)
void printPascalsTriangle(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << nCr(i - 1, j) << " ";
        }
        cout << endl;
    }
}

// Optimal Approach Time Complexity O(n^2)
void printPascalsTriangleOptimal(int n)
{
    for (int i = 1; i <= n; i++)
    {
        long long val = 1;
        cout << val << " ";
        for (int j = 1; j < i; j++)
        {
            val = val * (i - j);
            val = val / j;
            cout << val << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Value at 5 and 4 is : ";
    printRandCthValue(5, 4);
    cout << "\n5th Row : ";
    printNthRowOptimal(5);
    cout << "\n---------------PASCAL'S TRIANGLE---------------\n";
    printPascalsTriangleOptimal(5);
    return 0;
}
