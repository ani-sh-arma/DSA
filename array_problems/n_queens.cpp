#include <bits/stdc++.h>
using namespace std;

void placeQueen(vector<vector<int>> &arr, int row, vector<vector<vector<int>>> &res,
                vector<int> &leftRow, vector<int> &lowerDiagonal,
                vector<int> upperDiagonal, int n, int &count)
{
    if (row >= arr.size())
    {
        res.push_back(arr);
        count++;
        return;
    }

    for (int col = 0; col < arr.size(); col++)
    {
        if (leftRow[col] == 0 && lowerDiagonal[row - col + n - 1] == 0 && upperDiagonal[row + col] == 0)
        {
            arr[row][col] = 1;
            leftRow[col] = 1;
            lowerDiagonal[row - col + n - 1] = 1;
            upperDiagonal[row + col] = 1;
            placeQueen(arr, row + 1, res, leftRow, lowerDiagonal, upperDiagonal, n, count);
            leftRow[col] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[row - col + n - 1] = 0;
            arr[row][col] = 0;
        }
    }
}

vector<vector<vector<int>>> nQueens(int n, int &count)
{
    vector<vector<vector<int>>> res;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    placeQueen(arr, 0, res, leftRow, lowerDiagonal, upperDiagonal, n, count);
    return res;
}

int main(int argc, char const *argv[])
{
    auto start = chrono::high_resolution_clock::now();

    int count = 0;
    vector<vector<vector<int>>> res = nQueens(4, count);

    auto end = chrono::high_resolution_clock::now();

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            for (int k = 0; k < res[i][j].size(); k++)
            {
                cout << res[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Total number of solutions : " << count << endl;
    auto properEnd = chrono::high_resolution_clock::now();
    cout << "Time taken : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    cout << "Total Time taken : " << chrono::duration_cast<chrono::microseconds>(properEnd - start).count() << " microseconds" << endl;

    return 0;
}