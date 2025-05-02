#include<bits/stdc++.h>
using namespace std;
int f(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(i==0){
        if(w%weight[0] == 0) return profit[0] * w/weight[0];
        else return 0;
    }
    if(dp[i][w] != -1) return dp[i][w];
    else{
        int notpick = 0 + f(i-1, w, profit, weight, dp);
        int pick = 0;
        if(w>=weight[i]) pick = profit[i] + f(i, w-weight[i], profit, weight, dp);
        return dp[i][w] = max(notpick, pick);
    }
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // vector<vector<int>> dp(n, vector<int>(w+1, 0));
    vector<int> prev(w+1, 0);
    // vector<int> curr(w+1, 0);

    for(int W=weight[0]; W<=w; W++){
        if(W%weight[0] == 0) prev[W] = profit[0] * W/weight[0];
    }

    for(int i=1; i<n; i++){
        for(int W=0; W<=w; W++){
            int notpick = 0 + prev[W];
            int pick = 0;
            if(W>=weight[i]) pick = profit[i] + prev[W-weight[i]];
            prev[W] = max(notpick, pick);
        }
        // prev = curr;
    }
    return prev[w];
    // return f(n-1, w, profit, weight, dp);
}