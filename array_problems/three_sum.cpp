#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum1 = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }

            int sum2 = sum1 + arr[j];
            for (int k = 0; k < n; k++)
            {
                if (k == j || k == i)
                {
                    continue;
                }

                int sum3 = sum2 + arr[k];
                if (sum3 == 0)
                {
                    vector<int> ans = {arr[i], arr[j], arr[k]};
                    sort(ans.begin(), ans.end());
                    st.insert(ans);
                }
            }
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

vector<vector<int>> brute(vector<int> arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> ans = {arr[i], arr[j], arr[k]};
                    sort(ans.begin(), ans.end());
                    st.insert(ans);
                }
            }
        }
    }
}

vector<vector<int>> better(vector<int> arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        set<int> hash;
        for (int j = i + 1; j < n; j++)
        {
            int third = 0 - (arr[i] + arr[j]);
            if (hash.find(third) != hash.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(third);
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

vector<vector<int>> optimal(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                res.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 0};
    vector<vector<int>> res = optimal(nums);

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