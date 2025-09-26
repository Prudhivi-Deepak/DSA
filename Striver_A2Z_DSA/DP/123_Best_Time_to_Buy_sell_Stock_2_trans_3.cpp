#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int buyorsell, vector<int> &arr, vector<vector<vector<int>>> &dp, int ntra){
        // cout << buyorsell  << " : "<<  ntra << endl;
        if(i>=arr.size() || ntra==0) return 0;

        // if(i==arr.size()-1){
        //     if(buyorsell==0) return arr[i];
        //     else return 0;
        // }

        if(dp[i][buyorsell][ntra]!=-1) return dp[i][buyorsell][ntra];

        int NT = f(i+1, buyorsell, arr, dp, ntra);
        int T = INT_MIN;

        if(buyorsell){
            T = -arr[i] + f(i+1, 0, arr, dp, ntra);
        }
        else{
            T = arr[i] + f(i+1, 1, arr, dp, ntra-1);
        }

        return dp[i][buyorsell][ntra] = max(NT, T);

    }

    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp, int max_trans) {
        if (ind == n || max_trans == 0)
            return 0;
        // || max_trans == 0
        if (dp[ind][buy][max_trans] != -1)
            return dp[ind][buy][max_trans];
        if (buy)
            return dp[ind][buy][max_trans] = max(
                       -prices[ind] + f(ind + 1, 0, prices, n, dp, max_trans),
                       0 + f(ind + 1, 1, prices, n, dp, max_trans));
        else
            return dp[ind][buy][max_trans] =
                       max(prices[ind] +
                               f(ind + 1, 1, prices, n, dp, max_trans - 1),
                           0 + f(ind + 1, 0, prices, n, dp, max_trans));
    }

public:
    int maxProfit(vector<int> & arr){
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        int n = arr.size();
        vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        // prev[0][1] = arr[n-1];

        prev[0][1] = arr[n-1];
        prev[0][2] = arr[n-1];

        for(int i=n-2; i>=0; i--){
            for(int bs=0; bs<2; bs++){
                for(int ntra=1; ntra<3; ntra++){
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

        return prev[1][2];
    }
    int maxProfitFirstTry(vector<int>& prices) {
        // 7 1 5 3 6 4
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>  prev(2, vector<int>(3, 0));
        // // base case if ind == n 0 - already dp is 0
        // 2 transactions b s b s
        //                0 1 2 3 - even - buy, odd - sell
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