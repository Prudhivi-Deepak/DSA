// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        // int maxi = 0;
        // int minimum = prices[0];
        // for (int i = 0; i < prices.size(); i++)
        // {
        //     minimum = min(minimum, prices[i]);
        //     maxi = max(maxi, prices[i] - minimum);
        // }
        // return maxi;

        int min_ele = INT_MAX, max_ele = INT_MIN, sum = 0;
        for (int i : prices)
        {
            if (i < min_ele)
            {
                min_ele = i;
                max_ele = INT_MIN;
            }
            else if (i > max_ele)
            {
                max_ele = i;
            }
            if (min_ele != INT_MAX && max_ele != INT_MIN)
            {
                sum = max(sum, max_ele - min_ele);
            }
        }
        return sum;
    }
};