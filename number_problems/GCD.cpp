#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int num1;
    int num2;
    int greatest;

    cout << "Enter a number1: ";
    cin >> num1;
    cout << "Enter a number1: ";
    cin >> num2;

    for (int i = 1; i <= min(num1, num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            greatest = i;
        }
    }
    cout << "Normal approach GCD  = " << greatest << "\n";
    cout << "Optimal approach GCD = " << gcd(num1, num2) << "\n";
    return 0;
}