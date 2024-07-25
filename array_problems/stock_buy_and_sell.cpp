#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;
    
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}