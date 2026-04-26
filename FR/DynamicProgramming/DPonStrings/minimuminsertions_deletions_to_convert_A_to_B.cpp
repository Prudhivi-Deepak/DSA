class Solution{
	public: 
	int minOperations(string str1, string str2) {
	int n1 = str1.size(), n2 = str2.size();

      vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

      for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
          if(str1[i]==str2[j]){
            dp[i][j] = 1+dp[i+1][j+1];
          }
          else{
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
          }
        }
      }

      return (n1+n2-2*dp[0][0]);
	} 
};