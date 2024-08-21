#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!res.empty() && end <= res.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        res.push_back({start, end});
    }
    return res;
}

vector<vector<int>> optimal(vector<vector<int>> arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    res.push_back(arr[0]);
    for (int i = 0; i < arr.size(); i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (res.back()[1] <= end && res.back()[1] >= start)
        {
            res.back()[1] = end;
        }
        else
        {
            res.push_back({start, end});
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = optimal(arr);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}
