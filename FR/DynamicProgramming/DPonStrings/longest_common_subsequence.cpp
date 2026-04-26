class Solution {
  public:
    int f(int i, int j, string str1, string str2, vector<vector<int>> &dp){
      if(i>=str1.size() || j>=str2.size()) return 0;

      if(dp[i][j]!=-1) return dp[i][j];

      if(str1[i]==str2[j]){
        return dp[i][j] = 1+f(i+1, j+1, str1, str2, dp);
      }

      return dp[i][j] = max(f(i, j+1, str1, str2, dp), f(i+1, j, str1, str2, dp));
    }

    int lcs(string str1, string str2) {
      int n1 = str1.size(), n2 = str2.size();
      vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
      // i goes from 0 to n1-1, j goes from 0 to n2-1

      // base case : 0

      for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
          if(str1[i]==str2[j]){
            dp[i][j] = 1+dp[i+1][j+1];
          }
          else{
            dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
          }
        }
      }

      return dp[0][0];

      // return f(0, 0, str1, str2, dp);
    }
};
