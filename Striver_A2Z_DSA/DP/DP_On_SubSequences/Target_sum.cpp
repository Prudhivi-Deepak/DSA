#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mod = 1e9+7;
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K+1, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        if(arr[0] <= K) dp[0][arr[0]] = 1;

        for(int i=1; i<n; i++){
            for(int k=0; k<=K; k++){
                int NT = dp[i-1][k];
                int T = (k>=arr[i]) ? dp[i-1][k-arr[i]] : 0;
                dp[i][k] = (NT+T)%mod;
            }
        }

        return dp[n-1][K]%mod;
    }
    int targetSum(int n, int target, vector<int>& arr) {
        int TotalSum = 0;
        for(int i=0; i<n; i++){
            TotalSum += arr[i];
        }

        int K1 = (TotalSum+target);
        // if(K1<0 ||
        // if(K1== 0 || 
        if(K1%2==1) return 0;
        else K1 = K1/2;
        // cout << K1 << endl;

        return perfectSum(arr, K1);
    }
    int targetSumFirstTry(int n, int target, vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) {
            return 0;
        }

        target = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        if (nums[0] <= target) dp[0][nums[0]] = 1;
        if (nums[0] == 0) {
            dp[0][0] = 2;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int a = dp[i - 1][t];
                int s = (t >= nums[i]) ? dp[i - 1][t - nums[i]] : 0;
                dp[i][t] = s + a;
            }
        }
        return dp[n - 1][target];
    }
};
