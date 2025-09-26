#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(j==0){
            return (i==0);
        }
        else if(i==0){
            while(j>0 && p[j-1]=='*') j--;
            return (j<1);
        }


        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j-1]=='*')
            return dp[i][j] = (f(i-1,j,s,p,dp) || f(i, j-1, s, p, dp));
        else if(p[j-1]=='?' || s[i-1]==p[j-1])
            return dp[i][j] = f(i-1, j-1, s, p,dp);
        
        return dp[i][j] = false;
    }
    bool isMatch(string str, string pat) {
        int n = str.size(), m= pat.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        vector<int> prev(m+1, 0), curr(m+1, 0);

        // dp[0][0] = 1;
        prev[0] = 1;

        for(int j=1; j<=m; j++){
            if(pat[j-1]=='*'){
                // dp[0][j] = 1;
                prev[j] = 1;
            }
            else
                break;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(pat[j-1]=='*')
                    // dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    curr[j] = prev[j] || curr[j-1];
                else if(pat[j-1]=='?' || str[i-1]==pat[j-1])
                    // dp[i][j] = dp[i-1][j-1];
                    curr[j] = prev[j-1];
                else
                    curr[j] = 0;
            }
            prev = curr;
        }
        return prev[m];
        // return dp[n][m];
        // return f(n, m, str, pat, dp);
    }
};