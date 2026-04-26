class Solution{
    public: 

    // a b c d e
    // 1 2 0 
    // a b f c e

    int f(int i, int j, string str1, string str2, int cnt, vector<vector<vector<int>>> &dp){
        if(i>=str1.size() || j>=str2.size()) return cnt;

        if(dp[i][j][cnt]!=-1){
            // cout << i << j << dp[i][j][cnt] << endl;
            return dp[i][j][cnt];
        }

        if(str1[i]==str2[j]) return dp[i][j][cnt] = f(i+1, j+1, str1, str2, cnt+1, dp);
        return dp[i][j][cnt] = max({cnt, f(i+1, j, str1, str2, 0, dp), f(i, j+1, str1, str2, 0, dp)});
    }

    
    int longestCommonSubstr (string str1, string str2){
        int n1=str1.size(), n2=str2.size();
        // int maxCnt = min(n1, n2);

        // vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(maxCnt+2, 0)));
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        // i goes from 0 to n-1, j from 0 to n2-1, cnt from o to max(n1, n2)
        // base case : cnt

        int maxCnt = 0;

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(str1[i]==str2[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                    maxCnt = max(maxCnt, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }

        return maxCnt;

        // return f(0, 0, str1, str2, 0, dp);
    }
};
