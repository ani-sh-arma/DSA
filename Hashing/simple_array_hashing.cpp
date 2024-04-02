#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[20] = {0,1,2,5,4,8,75,4,1,2,3,2,1,4,5,2,1,4,5,2};
    int hash[76] = {0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        hash[arr[i]]++;
    }

    int num;
    cout << "Enter number of queries : ";   
    cin >> num;

    while (num--)
    {
        int q;
        cout << "Query : ";
        cin >> q;
        cout << "Frequency : " << hash[q] << endl;
    }
    
    return 0;
}