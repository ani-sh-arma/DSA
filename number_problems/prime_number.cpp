#include <iostream>
#include <math.h>
using namespace std;

bool primeOrNot(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    if (primeOrNot(num))
    {
        cout << "Number is Prime" << endl;
    }
    else
    {
        cout << "Number is not Prime" << endl;
    }
    return 0;
}
