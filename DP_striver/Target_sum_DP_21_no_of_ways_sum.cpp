#include <bits/stdc++.h> 

using namespace std;
// similar to partition s1-s2 = D
// https://www.naukri.com/code360/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int targetSum(int n, int d, vector<int>& arr) {
    // Write your code here.
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
			temp[sum] = (pick+dp[sum]);
		}
		dp = temp;
	}
    return dp[k];
}
