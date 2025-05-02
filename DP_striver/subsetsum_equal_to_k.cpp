#include <bits/stdc++.h> 
using namespace std;
// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
bool f(int i, int ts, vector<int>& arr, vector<vector<bool>> &dp){
	if(ts==0) return dp[i][ts] = true;
	if(i==0) return dp[i][ts] = (arr[i]==ts);
	if(dp[i][ts]) return dp[i][ts];
	else{
		bool pick = false;
		if(ts>=arr[i]) pick = f(i-1, ts-arr[i], arr, dp);
		bool notpick = f(i-1, ts, arr, dp);
		return dp[i][ts] = pick | notpick;
	}
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	
    // vector<vector<bool>> dp(n, vector<bool>(k+1, false));

	vector<bool> dp(k+1, false);
	vector<bool> temp(k+1, false);
	dp[0] = true;
	temp[0] = true;
	dp[arr[0]] = true;
	for(int i=1; i<n; i++){
		temp[arr[i]] = true;
		for(int cs=1; cs<k+1; cs++){
			if(cs==0 || (i==0 && cs==arr[i])) continue;
			else{
				bool pick = false;
				if(cs>=arr[i]) pick = dp[cs-arr[i]];
				// f(i-1, ts-arr[i], arr, dp);
				bool notpick = dp[cs];
				// f(i-1, ts, arr, dp);
				temp[cs] = pick | notpick;
			}
		}
		dp = temp;
	}

	return dp[k];
	
	// cout << endl;

	// bool ans = f(n-1, k, arr, dp);
    // int ans = f(n-1, k, arr, dp);
	// vector<vector<bool>> dp1(n, vector<bool>(k+1, false));
	// for(int i=0; i<n; i++) dp1[i][0] = 1;
	// dp1[0][arr[0]] = true;
	// for(int i=1; i<n; i++){
	// 	dp1[i][arr[i]] = true;
	// 	for(int cs=1; cs<k+1; cs++){
	// 		if(cs==0 || (i==0 && cs==arr[i])) continue;
	// 		else{
	// 			bool pick = false;
	// 			if(cs>=arr[i]) pick = dp1[i-1][cs-arr[i]];
	// 			// f(i-1, ts-arr[i], arr, dp);
	// 			bool notpick = dp1[i-1][cs];
	// 			// f(i-1, ts, arr, dp);
	// 			dp1[i][cs] = pick | notpick;
	// 		}
	// 	}
	// }

	// for(int i=0; i<n; i++){
	// 	for(int cs=0; cs<k+1; cs++){
	// 		cout << " " << dp1[i][cs];
	// 	}
	// 	cout << endl;
	// }

	
	
	



    // cout << ans << endl;

	// 0 4
	// 0 1 2 3
	// 4 3 2 1

	// 1 0 0 0 1 0
	// 0 1 2 3 4 5
	// possible s1 sum = 0, 4
	// total_sum = 10
	// s2 sum => 11, 7 =>
	// diff 11, 3 => 3

	// 1
	//-1 1 -1 0 0 0 0 0 0 -1 0 
	// 0 1 2 3 4 5 6 7 8 9 10
	// 1 2 3 4

	//possible s1 sum = 1
	//total_sum = 10
	// s2 sum => 9
	// diff 1


	// 1 -1 0 1 1 0
	// 0  1 2 3 4 5

	// s1 sum = 0  3 4 , ts = 10
	// s2 sum = 10 7 6

	// diff   = 10 4 2


	// int min_sum = INT_MAX;
	// // for(int i=0; i<n; i++){
	// 	for(int j=0; j<k+1; j++){
	// 		cout << dp[1][j] << " ";
	// 		if(dp[1][j] == 1){
    //             // cout <<  << endl;
    //             min_sum = min(min_sum, abs((k-j)-j));
    //         }
	// 	}
		// cout << endl;
	// }

    // return ans;
}