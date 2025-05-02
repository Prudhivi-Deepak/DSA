
#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
    if(j==0) return i;
    if(i==0) return j;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i-1] == str2[j-1]) return dp[i][j] = f(i-1, j-1, str1, str2, dp);
    else{
        int ins = 1 + f(i, j-1, str1, str2, dp);
        int del = 1 + f(i-1, j, str1, str2, dp);
        int rep = 1 + f(i-1, j-1, str1, str2, dp);
        return dp[i][j] = min(ins, min(del, rep));
    }
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    vector<int> curr(m+1, -1), prev(m+1, -1);

    // for(int i=0; i<=n; i++) dp[i][0] = i;
    // for(int j=0; j<=m; j++) dp[0][j] = j;
    for(int j=0; j<=m; j++) prev[j] = j;
    for(int i=1; i<=n; i++){
        curr[0] = i;
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]) curr[j] = prev[j-1];
            else{
                int ins = 1 + curr[j-1];
                int del = 1 + prev[j];
                int rep = 1 + prev[j-1];
                curr[j] = min(ins, min(del, rep));
            }
        }
        prev = curr;
    }
    return prev[m];
    // return f(n, m, str1, str2, dp);
}