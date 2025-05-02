#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int n, vector<int>& arr, int k, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int max_ele= INT_MIN;
        int sum = INT_MIN;
        for(int j=i; j<i+k && j<n; j++){
            max_ele = max(max_ele, arr[j]);
            sum = max(sum, max_ele*(j-i+1) + f(j+1, n, arr, k, dp));
        }
        return dp[i] = sum;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){

            int max_ele= INT_MIN;
            int sum = INT_MIN;

            for(int j=i; j<i+k && j<n; j++){
                max_ele = max(max_ele, arr[j]);
                sum = max(sum, max_ele*(j-i+1) + dp[j+1]);
            }
            dp[i] = sum;
        }
        return dp[0];
        // return f(0, n, arr, k, dp);
    }
};