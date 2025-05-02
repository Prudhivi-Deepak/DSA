#include<bits/stdc++.h>
using namespace std;

int f(int i1, int i2,string s, string t, vector<vector<int>> &dp){
	if(i1<0 || i2<0) return 0;
	if(dp[i1][i2] != -1) return dp[i1][i2];
	if(s[i1]==t[i2]) return dp[i1][i2] = 1+f(i1-1, i2-1,s,t,dp);
	return dp[i1][i2] = max(f(i1-1, i2,s,t,dp), f(i1, i2-1,s,t,dp));
}

int lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();

	// vector<vector<int>> dp1(n, vector<int>(m, -1));
	// vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	vector<int> curr(m+1, 0), prev(m+1, 0);

	for(int i1=1; i1<=n; i1++){
		for(int i2=1; i2<=m; i2++){
			if(s[i1-1]==t[i2-1]) curr[i2] = 1+prev[i2-1];
			else curr[i2] = max(prev[i2], curr[i2-1]);
		}
		prev = curr;
	}
	return prev[m];
}