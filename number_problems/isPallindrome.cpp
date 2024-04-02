#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string x)
{
    string reversed;
    string original;
    for (char c : x)
    {
        if (isalnum(c))
        {
            original += tolower(c);
        }
    }
    cout << original << endl;

    for (int i = original.length() - 1; i >= 0; i--)
    {
        reversed += original[i];
    }
    return original == reversed;
}

int main(int argc, char const *argv[])
{
    string str = "A man, a plan, a canal: Panama";
    cout << str << " " << isPalindrome(str) << "\n";
    return 0;
}
