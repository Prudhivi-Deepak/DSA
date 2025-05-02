#include <bits/stdc++.h> 
using namespace std;

class Solution {
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp, int max_trans) {
        if (ind == n || max_trans == 0) return 0;
        if (dp[ind][buy][max_trans] != -1) return dp[ind][buy][max_trans];
        if (buy) 
            return dp[ind][buy][max_trans] = max(
                       -prices[ind] + f(ind + 1, 0, prices, n, dp, max_trans),
                        0 + f(ind + 1, 1, prices, n, dp, max_trans));
        else
            return dp[ind][buy][max_trans] =
                       max(
                        prices[ind] + f(ind + 1, 1, prices, n, dp, max_trans - 1),
                           0 + f(ind + 1, 0, prices, n, dp, max_trans));
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // vector<vector<int>>  prev(2, vector<int>(k+1, 0));
        vector<int> prev_1(k+1, 0), prev_0(k+1, 0); 

        for(int ind=n-1; ind>=0; ind--){
            // for(int buy=1; buy>=0; buy--){
                for(int mt=k; mt>0; mt--){
                    // if(buy){
                        prev_1[mt] =  max(-prices[ind]+prev_0[mt], prev_1[mt]);

                    // }
                    // else {
                        prev_0[mt] = max(prices[ind]+prev_1[mt-1], prev_0[mt]);
                    // }
                }
            // }
            // prev = curr;
        }
        return prev_1[k];
        // return f(0, 1, prices, n, dp, k);
    }
};