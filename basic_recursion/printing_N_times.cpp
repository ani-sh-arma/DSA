#include <iostream>
using namespace std;

void oneToN(int n){
    if(n == 0){
        return;
    }
    oneToN(n-1);
    cout << n << " ";
}

void NToOne(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    NToOne(n-1);
}

int main(int argc, char const *argv[])
{
    int num = 5;
    cout << "\nPrinting 1 to N: ";
    oneToN(num);
    cout << "\nPrinting N to 1: ";
    NToOne(num);
    return 0;
}
