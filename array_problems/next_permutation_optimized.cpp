#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> arr, int in, vector<vector<int>> &permutations)
{
    if (in >= arr.size())
    {
        permutations.push_back(arr);
        return;
    }

    for (int i = in; i < arr.size(); i++)
    {
        swap(arr[in], arr[i]);
        nextPermutation(arr, in + 1, permutations);
        // swap(arr[in], arr[i]); // this line is not required for needed output but is said to be useful in some cases
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 1, 2, 3};
    vector<int> copy = arr;
    vector<int> res = {};
    vector<vector<int>> permutations = {};
    sort(copy.begin(), copy.end());
    nextPermutation(copy, 0, permutations);

    for (int i = 0; i < permutations.size(); i++)
    {
        if (i == permutations.size() - 1)
        {
            res = permutations[0];
            break;
        }
        if (permutations[i] == arr)
        {
            res = permutations[i + 1];
            break;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    

    return 0;
}