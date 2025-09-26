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
        int f(int i, int buyorsell, vector<int> &arr, vector<vector<int>> &dp, int fee){
            if(i>arr.size()) return 0;
    
            if(i==arr.size()-1){
                if(buyorsell==0) return arr[i]-fee;
                else return 0;
            }
    
            if(dp[i][buyorsell]!=-1) return dp[i][buyorsell];
    
            int NT = f(i+1, buyorsell, arr, dp, fee);
            int T = INT_MIN;
    
            if(buyorsell){
                T = -arr[i] + f(i+1, 0, arr, dp, fee);
            }
            else{
                T = arr[i] - fee + f(i+1, 1, arr, dp, fee);
            }
    
            return dp[i][buyorsell] = max(NT, T);
    
        }
        // int stockBuySell(vector<int> arr, int n, int fee){
        int maxProfit(vector<int>& arr, int fee) {
            int n = arr.size();
            // vector<vector<int>> dp(n, vector<int>(2, -1));
            // return f(0, 1, arr, dp, fee);
            vector<int> prev(2, 0), curr(2, 0);
            prev[0] = arr[n-1]-fee;
    
            for(int i=n-2; i>=0; i--){
                for(int bs=0; bs<2; bs++){
                    // int NT = dp[i+1][bs];
                    int NT = prev[bs];
                    int T = INT_MIN;
    
                    if(bs)
                        T = -arr[i]+prev[0];
                    else
                        T = arr[i]-fee+prev[1];
                    curr[bs] = max(NT, T);
                }
                prev = curr;
            }
    
            return prev[1];
            
        }
        int maxProfitFirstTry(vector<int>& prices, int fee) {
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