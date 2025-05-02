#include <bits/stdc++.h> 
using namespace std;
class Solution {
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) return dp[ind][buy] =  max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0+f(ind+1, 1, prices, n, dp));
        else return dp[ind][buy] = max(prices[ind]+f(ind+1, 1, prices, n, dp), 0+f(ind+1, 0, prices, n, dp));
    }
    public: int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // vector<int> prev(2, 0), curr(2,0);
        // buy - 1, sell - 0
        int prev_buy = 0, prev_sell = 0, curr_buy = 0, profit = 0;
        // int curr_sell = 0;
        // base case if ind == n 0 - already dp is 0
        for(int ind=n-1; ind>=0; ind--){
            // for(int buy=1; buy>=0; buy--){
            //     if(buy){
            //         // dp[ind][buy] =  max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
            //         // curr[buy] =  max(-prices[ind]+prev[0], prev[1]);
            //         curr_buy =  max(-prices[ind]+prev_sell, prev_buy);
            //     }
            //     else {
            //         // dp[ind][buy] = max(prices[ind]+dp[ind+1][1], dp[ind+1][0]);
            //         // curr[buy] = max(prices[ind]+prev[1], prev[0]);
            //         curr_sell = max(prices[ind]+prev_buy, prev_sell);
            //     }
            // }
            curr_buy =  max(-prices[ind]+prev_sell, prev_buy);
            prev_sell = max(prices[ind]+prev_buy, prev_sell);
            prev_buy = curr_buy;
            // prev_sell = curr_sell;
            // prev = curr;
        }
        for(int i=1; i<n; i++){
            if(prices[i]-prices[i-1]>0){
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;
        // return prev_buy;
        // return f(0, 1, prices, n, dp);
    }
};