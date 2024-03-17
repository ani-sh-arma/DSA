#include <iostream>
#include <math.h>
using namespace std;

bool armstrong(int num, int count)
{
    int originalNum = num;
    int temp = 0;
    int digit;
    for (int i = 0; i < count; i++)
    {
        digit = num % 10;
        num = num / 10;
        temp = temp + pow(digit, count);
    }
    return temp == originalNum;
}

int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    int count = 0;
    while (num > 0)
    {
        count++;
        num = num / 10;
    }
    
    if (armstrong(num, count))
    {
        cout << "Number is Armstrong number" << endl;
    }
    else
    {
        cout << "Number is not Armstrong number" << endl;
    }

    return 0;
}
