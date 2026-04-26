int mod = 1e9+7;
class Solution{
  public: 

  int f(int i, int j, string s, string t, vector<vector<int>> &dp){
    // that means we reached end of t string return 1 way
    if(j==t.size()) return 1;
    if(i>=s.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int NotTake = f(i+1, j, s, t, dp);

    int Take = 0;

    if(s[i]==t[j]) Take = f(i+1, j+1, s, t, dp);
    
    return dp[i][j] = NotTake + Take;
  }

  int distinctSubsequences(string s, string t){
    // find lcs - dp array
    // we have lcs value untill i j for dp[i][j]
    // we have to find no. of subsequences equal to t right let's try recursion first

    int n1 = s.size(), n2 = t.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    // i,j goes from 0 to n1-1, n2-1
    // base case : dp[i][n2] = 1;

    for(int i=0; i<=n1; i++){
      dp[i][n2] = 1;
    }

    for(int i=n1-1; i>=0; i--){
      for(int j=n2-1; j>=0; j--){
        int NotTake = dp[i+1][j];
        int Take = (s[i]==t[j]) ? dp[i+1][j+1] : 0;
        dp[i][j] = (NotTake + Take)%mod;
      }
    }

    return dp[0][0]%mod;

    // return f(0, 0, s, t, dp);
	}
};