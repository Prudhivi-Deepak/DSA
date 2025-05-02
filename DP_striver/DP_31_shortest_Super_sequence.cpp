#include <bits/stdc++.h> 
using namespace std;
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n = a.size();
	int m = b.size();
	// vector<int> curr(m+1,0), prev(m+1,0);
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	int i=n, j=m;
	string s = "";
	while(i>0 && j>0){
		if(a[i-1] == b[j-1]){
			s = a[i-1] + s;
			i--;j--;
		}
		else if(dp[i-1][j]>=dp[i][j-1]){
			s = a[i-1] + s;
			i--;
		}
		else{
			s = b[j-1] + s ;
			j--;
		}
	}

	while(i>0){
		s = a[i-1] + s;
		i--;
	}

	while(j>0){
		s = b[j-1] + s;
		j--;
	}
	return s;
}