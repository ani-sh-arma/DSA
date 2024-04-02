#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "AnkitPatil07";
    int hash[256] = {0};
    for (int i = 0; i < str.length(); i++){
        hash[str[i]]++;
    }
    int num;
    cout << "Enter number of queries : ";
    cin >> num;
    while (num--){
        char q;
        cout << "Query : ";
        cin >> q;
        cout << "Frequency : " << hash[q] << endl;
    }
    return 0;
}
