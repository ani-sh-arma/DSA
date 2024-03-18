#include <iostream>
using namespace std;


// without returning a value
void sumOfNnumbers(int n, int sum){
    if(n <= 0){
        cout << "Sum = " << sum << endl;
        return;
    }
    sumOfNnumbers(n-1, sum + n);
}

// Returning a value

int sum(int n){
    if(n <= 0){
        return 0;
    }
    return n + sum(n-1);
}

int main(int argc, char const *argv[])
{
    sumOfNnumbers(10, 0);
    cout << "Return Sum = " << sum(10) << endl;
    return 0;
}
