#include <iostream>
#include <vector>
using namespace std;

main(int argc, char const *argv[])
{
    int num;
    cout << "Enter a number : ";
    cin >> num;

    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << num;
    return 0;
}
