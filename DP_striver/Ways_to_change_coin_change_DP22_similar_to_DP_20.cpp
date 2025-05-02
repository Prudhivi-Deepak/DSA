#include<bits/stdc++.h>
// https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
using namespace std;
long f(int ind, int x, vector<int> &num, vector<vector<long>> &dp){
    if(x==0) return 1;
    if(ind ==0 ){
        if(x%num[0]==0) return 1;
        else return 0;
    }
    if(dp[ind][x] != -1) return dp[ind][x];
    else{
        long nottake = f(ind-1, x, num, dp);
        long take = 0;
        if(x>=num[ind]) take = f(ind, x-num[ind], num, dp);
        // cout << ind << " " << x << " " << nottake + take << endl;
        return dp[ind][x] = nottake + take;
    }
}
long countWaysToMakeChange(int *num, int n, int x){
    //Write your code here
    // vector<vector<long>> dp(n, vector<long>(value+1, -1));
    // vector<int> num(denominations, denominations+n);
    // int x = value;
    vector<long> prev(x+1, 0), curr(x+1, 0);
    // int ans = f(n-1, x, num, dp);
    for(int X=0; X<=x; X++){
        if(X%num[0]==0) prev[X] = 1;
    }

    for(int i=1; i<n; i++){
        for(int X=0; X<=x; X++){
            long nottake = prev[X];
            long take = 0;
            if(X>=num[i]) take = curr[X-num[i]];
            curr[X] = nottake + take;
        }
        prev = curr;
    }
    return prev[x];
    // return f(n-1, value, num, dp);
}