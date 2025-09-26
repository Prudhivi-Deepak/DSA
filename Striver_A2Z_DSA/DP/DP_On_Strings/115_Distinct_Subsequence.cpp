#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
        // if(j<0) return 1;
        // if(i<0) return 0;

        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int NT = f(i-1, j, s, t, dp)%mod;
        // int T = (s[i]==t[j]) ? 1+f(i-1, j-1, s, t, dp)%mod : 0+f(i-1, j, s, t, dp)%mod;
        int T = (s[i-1]==t[j-1]) ? f(i-1, j-1, s, t, dp)%mod : 0 ;

        return dp[i][j] = (NT+T)%mod;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] =1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int NT = dp[i-1][j]%mod;
                int T = (s[i-1]==t[j-1]) ? dp[i-1][j-1]%mod : 0;
                dp[i][j] = (NT+T)%mod;
            }
        }
        return dp[n][m]%mod;
        // return f(n-1, m-1, s, t, dp);
        // return f(n, m, s, t, dp);
    }
};