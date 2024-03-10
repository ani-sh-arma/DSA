#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number: " ;
    int num;
    cin >> num ;

    int count = 0;
    int reversed = 0;

    int loop_num = num;
    while (loop_num > 0)
    {
        count++;
        int temp = loop_num % 10;
        reversed =  (reversed*10) + temp;
        loop_num = loop_num / 10;
    }

    if (num == reversed)
    {
        cout << count << "\n";
        cout << reversed << "\n";
        cout << "Number is pallindrome" << "\n";
    }
    else
    {
        cout << count << "\n";
        cout << reversed << "\n";
        cout << "Number is not pallindrome" << "\n";        
    }
    
    return 0;
}
