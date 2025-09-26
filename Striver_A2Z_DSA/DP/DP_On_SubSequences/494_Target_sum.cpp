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
    
            if(arr[0]==0) dp[0][arr[0]] = 2;
    
            for(int i=1; i<n; i++){
                for(int k=0; k<=K; k++){
                    int NT = dp[i-1][k];
                    int T = (k>=arr[i]) ? dp[i-1][k-arr[i]] : 0;
                    dp[i][k] = (NT+T)%mod;
                }
            }
    
            return dp[n-1][K]%mod;
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();
            int TotalSum = 0;
            for(int i=0; i<n; i++){
                TotalSum += nums[i];
            }
    
            int K1 = (TotalSum+target);
            // if(K1<0 ||
            // if(K1== 0 || 
            if(K1<0 || K1%2==1) return 0;
            else K1 = K1/2;
            // cout << K1 << endl;
    
            return perfectSum(nums, K1);       
    
        }
    };