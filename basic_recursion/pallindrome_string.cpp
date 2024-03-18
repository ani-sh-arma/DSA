#include <iostream>
using namespace std;

bool isPallindrome(int i, string& s)
{
    if(i>=s.length()/2) return true;
    
    if(s[i]!=s[s.length()-i-1]) return false;

    return isPallindrome(i+1,s);  
}

int main()
{
    string s = "madam";
    cout << "Is the string pallindrome? : " << isPallindrome(0, s) << endl;
    return 0;
}