#include<bits/stdc++.h>
using namespace std;
int f(int i, int w, vector<int> &profit, vector<vector<int>> &dp){
    if(i==0){
        return profit[0] * w;
    }
    if(dp[i][w] != -1) return dp[i][w];
    else{
        int notpick = 0 + f(i-1, w, profit, dp);
        int pick = 0;
        int rod_length = i+1;
        if(rod_length<=w) pick = profit[i] + f(i, w-rod_length , profit, dp);
        return dp[i][w] = max(notpick, pick);
    }
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// vector<vector<int>> dp(n, vector<int>(n+1, 0));
    vector<int> prev(n+1, 0);

    for(int p=0; p<=n; p++) prev[p] = price[0]*p;

    for(int i=1; i<n; i++){
        for(int p=0; p<=n; p++){
            int notpick = 0 + prev[p];
            int pick = 0;
            int rod_length = i+1;
            if(rod_length<=p) pick = price[i] + prev[p-rod_length];
            prev[p] = max(notpick, pick);
        }
        // prev = curr;
    }
    return prev[n];
	// return f(n-1, n ,price, dp);
}
