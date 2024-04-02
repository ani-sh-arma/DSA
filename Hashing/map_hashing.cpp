#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[20] = {0, 1, 2, 5, 4, 8, 75, 4, 1, 2, 3, 2, 1, 4, 5, 2, 1, 4, 5, 2};
    map<int, int> mp;
    for (int i = 0; i < 20; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " -> " << it.second << endl;
    }
    
    int num;
    cout << "Enter number of queries : ";
    cin >> num;
    while (num--)
    {
        int q;
        cout << "Query : ";
        cin >> q;
        cout << "Frequency : " << mp[q] << endl;
    }
    return 0;
}
