#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> A = {
        vector<int>{1, 2, 3},
        vector<int>{4, 5, 6},
        vector<int>{7, 8, 9},
    };

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A[i].size(); j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        reverse(A[i].begin(), A[i].end());
    }
    
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}