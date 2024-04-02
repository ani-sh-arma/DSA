#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "ankitpatil";
    int hash[26] = {0};
    for (int i = 0; i < str.length(); i++){
        hash[str[i] - 'a']++;
    }
    int num;
    cout << "Enter number of queries : ";
    cin >> num;
    while (num--){
        char q;
        cout << "Query : ";
        cin >> q;
        cout << "Frequency : " << hash[q - 'a'] << endl;
    }
    return 0;
}
