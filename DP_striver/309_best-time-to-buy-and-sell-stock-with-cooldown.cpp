#include <bits/stdc++.h> 
using namespace std;

class Solution {

    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) return dp[ind][buy] =  max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0+f(ind+1, 1, prices, n, dp));
        else return dp[ind][buy] = max(prices[ind]+f(ind+2, 1, prices, n, dp), 0+f(ind+1, 0, prices, n, dp));
    }
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            // vector<vector<int>> dp(n+2, vector<int>(2, 0));
            vector<int> prev1(2, 0), curr(2, 0);
            int prev2_1 = 0;
            for(int ind=n-1; ind>=0; ind--){
                curr[1] = max(-prices[ind]+prev1[0], 0+prev1[1]);
                curr[0] = max(prices[ind]+prev2_1, 0+prev1[0]);
                prev2_1 = prev1[1];
                prev1 = curr;
            }
            return prev1[1];
            // return f(0, 1, prices, n, dp);
        }
    };