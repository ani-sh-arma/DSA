#include <bits/stdc++.h>
using namespace std;

// Works for square matrix only.
vector<int> spiralTraversal(vector<vector<int>> arr)
{
    vector<int> res;
    for (int k = 0; k <= arr.size() / 2; k++)
    {
        for (int i = k; i < arr.size() - k; i++)
        {
            if (i == k)
            {
                for (int j = k; j < arr[i].size() - k; j++)
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
                for (int j = arr.size() - 1 - k; j > k; j--)
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

vector<int> optimalApproach(vector<vector<int>> arr)
{
    vector<int> res;
    int n = arr.size(), m = arr[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            res.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            res.push_back(arr[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(arr[i][left]);
            }
            left++;
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
        vector<int>{21, 22, 23, 24},
        vector<int>{25, 26, 27, 28},
    };
    // Expected answer = 1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10
    vector<int> res = optimalApproach(A);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}