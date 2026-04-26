class Solution{
  public:
    // at first no cuts n length to 0

    int f(int i, vector<int> price, int n, vector<vector<int>> &dp){
      if(n<=0) return 0;
      if(i==0){
        return n*price[0];
      }

      if(dp[i][n]!=-1) return dp[i][n];

      int NotTake = 0 + f(i-1, price, n, dp);
      int take = 0;
      if(n>=(i+1)) take = price[i] + f(i, price, n-(i+1), dp);

      return dp[i][n] = max(NotTake, take);

    }

    int rodCutting(vector<int> price, int n) {
      vector<vector<int>> dp(n, vector<int>(n+1, 0));

      // i goes from n-1 to 0
      // base case : dp[0][] = n*price[0];
      for(int n1=1; n1<=n; n1++){
        dp[0][n1] = n1*price[0];
      }

      for(int i=1; i<n; i++){
        for(int n1=1; n1<=n; n1++){
          int NotTake = 0 + dp[i-1][n1];
          int take = 0;
          if(n1>=(i+1)) take = price[i] + dp[i][n1-(i+1)];

          dp[i][n1] = max(NotTake, take);
        }
      }

      return dp[n-1][n];


      // return f(n-1, price, n, dp);
    }
};
