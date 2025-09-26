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
    //Revision
    int maxProfit(int k, vector<int> arr){
        int n = arr.size();
        vector<vector<int>> prev(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        // prev[0][1] = arr[n-1];

        // prev[0][1] = arr[n-1];
        // prev[0][2] = arr[n-1];

        for(int ktrans = 1; ktrans<=k; ktrans++){
            prev[0][ktrans] = arr[n-1];
        }

        for(int i=n-2; i>=0; i--){
            for(int bs=0; bs<2; bs++){
                for(int ntra=1; ntra<=k; ntra++){
                    // int NT = dp[i+1][bs];
                    int NT = prev[bs][ntra];
                    int T = INT_MIN;

                    if(bs)
                        T = -arr[i]+prev[0][ntra];
                    else
                        T = arr[i]+prev[1][ntra-1];
                    curr[bs][ntra] = max(NT, T);
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }
    int maxProfitFirstTry(int k, vector<int>& prices) {
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