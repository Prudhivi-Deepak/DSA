#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp, int max_trans) {
        if (ind == n || max_trans == 0)  return 0;
        if (dp[ind][buy][max_trans] != -1) return dp[ind][buy][max_trans];
        if (buy) return dp[ind][buy][max_trans] = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, max_trans), 0 + f(ind + 1, 1, prices, n, dp, max_trans));
        else return dp[ind][buy][max_trans] = max(prices[ind] + f(ind + 1, 1, prices, n, dp, max_trans - 1), 0 + f(ind + 1, 0, prices, n, dp, max_trans));
    }

public:
    int maxProfit(vector<int>& prices) {
        // 7 1 5 3 6 4
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>  prev(2, vector<int>(3, 0));
        // // base case if ind == n 0 - already dp is 0
        for (int ind = n - 1; ind >= 0; ind--) {
            prev[1][2] = max(-prices[ind] + prev[0][2], prev[1][2]);
            prev[0][2] = max(prices[ind] + prev[1][1], prev[0][2]);

            prev[1][1] = max(-prices[ind] + prev[0][1], prev[1][1]);
            prev[0][1] = max(prices[ind] + prev[1][0], prev[0][1]);
        }
        return prev[1][2];
        // return f(0, 1, prices, n, dp, 2);
    }
};