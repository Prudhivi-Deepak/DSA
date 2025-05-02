#include <bits/stdc++.h> 
// https://www.naukri.com/code360/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION&customSource=studio_nav
using namespace std;
int f(int i, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
	if(maxWeight == 0) return 0;
	if (i==0){
		if(maxWeight >= weight[0]) return value[0];
		else return 0;
	}
	if(dp[i][maxWeight] != -1) return dp[i][maxWeight];
	else{
		int pick = 0;
		if(maxWeight >= weight[i]) pick = value[i] + f(i-1, maxWeight-weight[i], weight, value, dp);
		int notpick = f(i-1, maxWeight, weight, value, dp);
		return dp[i][maxWeight] = max(pick, notpick);
	}
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));// care with dp sizes
	vector<int> dp(maxWeight+1, 0);
	// vector<int> temp(maxWeight+1, 0);
	for(int w=weight[0]; w<=maxWeight; w++){ // got it
		// if(w >= weight[0])
		 dp[w] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int w=maxWeight; w>=0; w--){
			int pick = 0;
			if(w >= weight[i]) pick = value[i] + dp[w-weight[i]];
			// if(w >= weight[i]) pick = value[i] + dp[i-1][w-weight[i]];
			// f(i-1, maxWeight-weight[i], weight, value, dp);
			// int notpick = dp[i-1][w];
			int notpick = dp[w];
			// f(i-1, maxWeight, weight, value, dp);
			// dp[i][w] = max(pick, notpick);
			dp[w] = max(pick, notpick);
		}
		// dp = temp;
	}
	return dp[maxWeight];
	// return f(n-1, maxWeight, weight, value, dp);
}