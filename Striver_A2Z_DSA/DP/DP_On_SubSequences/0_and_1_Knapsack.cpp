#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
     int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
         // vector<vector<int>> dp(n, vector<int>(W+1, 0));
         vector<int> curr(W+1, 0), prev(W+1, 0);
         for (int i = wt[0]; i <= W; i++) {
             // dp[0][i] = val[0];
             prev[i] = val[0];
         }
 
         if(W>=wt[0]) prev[wt[0]]= val[0];
         for(int i=1; i<n; i++){
             for(int w=1; w<=W; w++){
                 int NT = prev[w];
                 int T = (w>=wt[i])? prev[w-wt[i]]+val[i] : 0;
                 curr[w] = max(NT, T);
             }
             prev = curr;
         }
         return prev[W];
     }
 };