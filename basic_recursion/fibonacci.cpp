#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int secLast = fibonacci(n - 2);
    int last = fibonacci(n - 1);
    return secLast + last;
}

int main()
{
    int num = 11;
    cout << fibonacci(num-1);
    return 0;
}