#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int f(int ind, int buy, int fee, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) return dp[ind][buy] =  max(-prices[ind] + f(ind+1, 0, fee, prices, n, dp), 0+f(ind+1, 1, fee, prices, n, dp));
        else return dp[ind][buy] = max(prices[ind]+f(ind+1, 1, fee, prices, n, dp)-fee, 0+f(ind+1, 0, fee, prices, n, dp));
    }
    
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            // vector<vector<int>> dp(n+1, vector<int>(2, 0));
            // vector<int> prev(2, 0), curr(2, 0);
            int prev_buy = 0, prev_sell = 0, curr_buy = 0;
    
            for(int ind=n-1; ind>=0; ind--){
                curr_buy = max(-prices[ind]+prev_sell, prev_buy);
                prev_sell = max(prices[ind]+prev_buy-fee, prev_sell);
                prev_buy = curr_buy;
            }
            return prev_buy;
            // return f(0, 1, fee, prices, n, dp);
        }
    };