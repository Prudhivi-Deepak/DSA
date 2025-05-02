#include <bits/stdc++.h> 
using namespace std;
int modulo = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    // int n = arr.size();
	// vector<vector<int>> dp1(n, vector<int>(k+1, 0));
	// unordered_map<int, unordered_map<int, int>> dp;
	// unordered_map<int, int> dp;
	// unordered_map<int, int> temp;
	int totalsum=0;
	for(int i: arr){
		totalsum += i;
	}
	if(d>totalsum || (totalsum-d)%2==1) return 0;
	int k = (totalsum-d)/2;

	vector<int> dp(k+1, 0);
	vector<int> temp(k+1, 0);

	dp[0] = 1;
	temp[0] = 1;
	for(int i=0; i<n; i++){
		for(int sum = k; sum>=0; sum--){
			int pick=0;
			if(sum>=arr[i]){
				pick = dp[sum-arr[i]];
			}
			temp[sum] = (pick+dp[sum])%modulo;
		}
		dp = temp;
	}
    return dp[k];
	// return 0;
}


