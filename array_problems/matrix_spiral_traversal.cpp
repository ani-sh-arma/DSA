#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> arr)
{
    vector<int> res;
    for (int k = 0; k < arr.size() / 2; k++)
    {
        for (int i = k; i < arr.size() - k; i++)
        {
            if (i == k)
            {
                for (int j = 0; j < arr[i].size() - k; j++)
                {
                    res.push_back(arr[i][j]);
                }
            }
            else if (i == arr.size() - 1 - k)
            {
                for (int j = arr[i].size() - 1 - k; j > k; j--)
                {
                    cout << arr[i][j] << endl;
                    res.push_back(arr[i][j]);
                }
                for (int j = arr.size() - 1 - k; j > 1; j--)
                {
                    res.push_back(arr[j][k]);
                }
            }
            else
            {
                res.push_back(arr[i][arr[i].size() - 1 - k]);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> A = {
        vector<int>{1, 2, 3, 4},
        vector<int>{5, 6, 7, 8},
        vector<int>{9, 10, 11, 12},
        vector<int>{13, 14, 15, 16},
        vector<int>{17, 18, 19, 20},
    };
    // Expected answer = 1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10
    vector<int> res = spiralTraversal(A);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}