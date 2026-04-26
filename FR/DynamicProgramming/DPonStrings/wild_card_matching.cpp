class Solution {
public:
    bool f(int i, int j, string str, string pat, vector<vector<int>> &dp){
        if(i==str.size() && j==pat.size()) return true;
        
        if(j==pat.size()) return false;
        
        if(i==str.size()){
            int k=j;
            while(k<pat.size()){
                if(pat[k]!='*') return false;
                k++;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(pat[j] == str[i]) return dp[i][j] = f(i+1, j+1, str, pat, dp);
        else if(pat[j]=='?') return dp[i][j] = f(i+1, j+1, str, pat, dp);
        else if(pat[j] == '*')
            return dp[i][j] = (f(i+1, j, str, pat, dp) || f(i, j+1, str, pat, dp));
        return dp[i][j] = false;
    }

    bool wildCard(string str, string pat) {
        // cout << str << endl;
        int n = str.size(), m = pat.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // i,j goes from 0 to n, 0 to m
        // base case: dp[n][m] = 1, j==m for any i =0, if i=n , j should be '*'
        // dp[n][m] = 1;
        prev[m] = 1;

        for(int j=m-1; j>=0; j--){
            if(pat[j]!='*') break;
            // dp[n][j] = 1;
            prev[j] = 1;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                // if(pat[j] == str[i]) dp[i][j] = dp[i+1][j+1];
                // else if(pat[j]=='?') dp[i][j] = dp[i+1][j+1];
                // else if(pat[j] == '*') dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                // else dp[i][j] = false;
                if(pat[j] == str[i]) curr[j] = prev[j+1];
                else if(pat[j]=='?') curr[j] = prev[j+1];
                else if(pat[j] == '*') curr[j] = (prev[j] || curr[j+1]);
                else curr[j] = false;
            }
            prev = curr;
        }

        // return dp[0][0];
        return prev[0];

        // return f(0, 0, str, pat, dp);
    }
};
