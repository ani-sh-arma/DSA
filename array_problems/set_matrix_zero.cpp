#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZero(vector<vector<int>> arr, int rowNo, int colNo)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == rowNo)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                arr[i][j] = 0;
            }
        }
        arr[i][colNo] = 0;
    }
    return arr;
}

vector<vector<int>> bruteForce(vector<vector<int>> arr)
{
    vector<vector<int>> res = arr;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                res = setMatrixZero(res, i, j);
            }
        }
    }
    return res;
}

vector<vector<int>> optimalApproach(vector<vector<int>> arr)
{
    int col0 = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr[i].size(); j++)
        {
            if (arr[0][j] == 0 || arr[i][0] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    if (arr[0][0] == 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[0][i] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i][0] = 0;
        }
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {0, 0, 9}};
    vector<vector<int>> res = optimalApproach(arr);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
