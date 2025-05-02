int mod = 1e9+7;
#include <bits/stdc++.h> 
using namespace std;
int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp){

	if(j==0) return 1;
	if(i==0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(str[i-1] == sub[j-1]) return dp[i][j] = f(i-1, j-1, str, sub, dp)%mod + f(i-1, j, str, sub, dp)%mod;
	else return dp[i][j] = f(i-1, j, str, sub, dp)%mod;
}

int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.size();
	int m = sub.size();
	// vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	vector<int> curr(m+1, 0);

	curr[0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=m; j>=0; j--){
			if(str[i-1] == sub[j-1]) curr[j] = curr[j-1]%mod + curr[j]%mod;
			// else curr[j] = prev[j]%mod;
		}
		// prev = curr;
	}
	return curr[m];
	// return f(n, m, str, sub, dp);
}
