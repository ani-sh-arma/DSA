#include <iostream>
#include <typeinfo>
using namespace std;

bool pallindrome(int num , int count){
    
    int middle = count/2;
    string str_num = to_string(num);

    if (count % 2 == 0)
    {
        string first_half = str_num.substr(0, middle);
        string second_half = str_num.substr(middle , string::npos);
        string rev_half = "";

        for (int i = second_half.length() - 1; i >= 0; i--)
        {
            rev_half = rev_half + second_half[i];
        }

        if (first_half == rev_half)
        {
            return true;
        }
        return false;
    }
    else
    {
        string first_half = str_num.substr(0, middle);
        string second_half = str_num.substr(middle + 1 , string::npos);
        string rev_half = "";

        for (int i = second_half.length() - 1 ; i >= 0; i--)
        {
            rev_half = rev_half + second_half[i];
        }
        if (first_half == rev_half) 
        {
            return true;
        }
        return false;        
    }
}

int main()
{
    cout << "Enter a number: " ;
    int num;
    cin >> num ;

    int count = 0;
    string reversed = "";

    int loop_num = num;

    while (loop_num > 0)
    {
        count++;
        int temp = loop_num % 10;
        reversed =  reversed + to_string(temp);
        loop_num = loop_num / 10;
    }

    if (pallindrome(num , count) == 1)
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
