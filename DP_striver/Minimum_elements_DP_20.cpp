#include <bits/stdc++.h> 
using namespace std;
// https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries&leftPanelTabValue=PROBLEM
int f(int ind, int x, vector<int> &num, vector<vector<int>> &dp){
    if(ind ==0 ){
        if(x%num[0]==0) return x/num[ind];
        else return 1e9;
    }
    if(dp[ind][x] != -1) return dp[ind][x];
    else{
        int nottake = 0 + f(ind-1, x, num, dp);
        int take = 1e9;
        if(x>=num[ind]) take = 1 + f(ind, x-num[ind], num, dp);
        return dp[ind][x] = min(nottake, take);
    }
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    // vector<vector<int>> dp(n, vector<int>(x+1, 1e9));
    vector<int> prev(x+1, 1e9), curr(x+1, 1e9);
    // int ans = f(n-1, x, num, dp);
    for(int X=0; X<=x; X++){
        if(X%num[0]==0) prev[X] = X/num[0];
    }

    for(int i=1; i<n; i++){
        for(int X=0; X<=x; X++){
            int nottake = prev[X];
            int take = 1e9;
            if(X>=num[i]) take = 1 + curr[X-num[i]];
            curr[X] = min(nottake, take);
        }
        prev = curr;
    }

    if(prev[x] >= 1e9){
        return -1;
    }
    return prev[x];
}