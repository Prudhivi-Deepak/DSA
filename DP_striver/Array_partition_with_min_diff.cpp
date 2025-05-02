// int f(int ind, int diff, vector<int>& arr, int n, vector<vector<int>> & dp){
// 	// if (diff<0) return INT_MAX;
// 	if(ind <0) return abs(diff);
// 	if(dp[ind][abs(diff)]!=INT_MAX) return dp[ind][abs(diff)];
// 	else{
// 		int add = f(ind-1, diff+arr[ind], arr, n, dp);
// 		int sub = f(ind-1, diff-arr[ind], arr, n, dp);
// 		return dp[ind][abs(diff)] = min(add, sub);
// 	}
// }
#include <bits/stdc++.h> 
using namespace std;
// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
// pick not pick code
bool f(int i, int ts, vector<int>& arr, vector<vector<int>> &dp){
	if(i==0) return  (arr[i]==ts);
	if(ts==0) return  true;
	if(dp[i][ts]!=-1) return dp[i][ts];
	else{
		bool pick = false;
		if(ts>=arr[i]) pick = f(i-1, ts-arr[i], arr, dp);
		bool notpick = f(i-1, ts, arr, dp);
		return dp[i][ts] = pick | notpick;
	}
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k = 0;
	for(int i=0; i<n; i++) k += arr[i];
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

	int min_sum = 1e9;
	int ts = k;
	k = k/2+1;
	// cout << k << endl;
	for(int i=0; i<=k; i++){
		// cout << i << " " <<  dp[i] << endl;
		if(dp[i] == 1){
			min_sum = min(min_sum, abs((ts-i)-i));
		}
	}

	return min_sum;

	// return dp[k];
	// 0 4
	// 0 1 2 3
	// 4 3 2 1

	// 1 0 0 0 1 0
	// 0 1 2 3 4 5
	// possible s1 sum = 0, 4
	// total_sum = 11
	// s2 sum => 11, 7 =>
	// diff 11, 3 => 3

	// 0 1 2 3
	// 1 2 3 4



	// int total_sum = 0;
	// for(int i: arr){
	// 	total_sum += i;
	// }
	// // Write your code here.
	// vector<vector<int>> dp(n, vector<int>(total_sum+1, -1));
	// f(n-1, total_sum, arr, dp);


	// int diff = arr[0];
	// dp[0][diff] = diff;
	// for(int i=0; i<n; i++){

	// 	if(i==0){
	// 		// dp[i][abs(diff)] = diff - arr[i];
	// 		// dp[i][abs(total_sum)] = total_sum - arr[i];
	// 		continue;
	// 	}

	// 	int add = dp[i-1][abs(diff+arr[i])];
	// 	// f(ind-1, diff+arr[ind], arr, n, dp);
	// 	int sub = dp[i-1][abs(diff-arr[i])];
	// 	// f(ind-1, diff-arr[ind], arr, n, dp);
	// 	dp[i][abs(diff)] = min(add, sub);
	// }

	// return dp[n-1][0];


	// return f(arr.size()-1, 0, arr, n, dp);
}
