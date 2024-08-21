#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

vector<vector<int>> better(vector<int> arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> elems;
            for (int k = j + 1; k < n; k++)
            {
                int elem = target - (arr[i] + arr[j] + arr[k]);
                if (elems.find(elem) != elems.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], elem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                elems.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

vector<vector<int>> optimal(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++, l--;

                    while (k < l && arr[k] == arr[k - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = optimal(arr, 0);

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
