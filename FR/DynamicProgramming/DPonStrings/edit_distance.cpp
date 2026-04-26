class Solution {
  public:

    int f(int i, int j, string start, string target, vector<vector<int>>  &dp){
      if(i==0) return j; 
      if(j==0) return i;

      if(dp[i][j]!=-1) return dp[i][j];

      if(start[i-1]==target[j-1]) return dp[i][j] = f(i-1, j-1, start, target, dp);

      int insert = f(i, j-1, start, target, dp);
      int del = f(i-1, j, start, target, dp);
      int replace = f(i-1, j-1, start, target, dp);
      
      return dp[i][j] = min({insert, del, replace})+1;
    }
    
    int editDistance(string start, string target) {
      int n = start.size(), m = target.size();
      if(n==0) return m;
      if(m==0) return n;
      vector<vector<int>>  dp(n+1, vector<int>(m+1, 0));
      // i, j goes from n-1, m-1 to <0
      // base case <0 dp[<0][j] = j+1, dp[i][<0] = i+1

      for(int i=0; i<=n; i++){
        dp[i][0] = i;
      }

      for(int j=0; j<=m; j++){
        dp[0][j] = j;
      }

      for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
          if(start[i-1]==target[j-1]) dp[i][j] = dp[i-1][j-1];
          else{
            int insert = dp[i][j-1];
            int del = dp[i-1][j];
            int replace = dp[i-1][j-1];
            
            dp[i][j] = min({insert, del, replace})+1;
          }
        }
      }
      return dp[n][m];
      // return f(n, m, start, target, dp);
    }
};

