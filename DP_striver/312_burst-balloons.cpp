#include<bits/stdc++.h>
using namespace std;

class Solution {

    int f(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int ind=i; ind<=j; ind++){
            // cout << i-1 << " " << ind << " " << j+1 << endl;
            maxi = max(maxi, nums[i-1]*nums[ind]*nums[j+1]+ f(i, ind-1, nums, dp) + f(ind+1, j, nums, dp));
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=n-2; i>=1; i--){
            for(int j=1; j<=n-2; j++){
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int ind=i; ind<=j; ind++){
                    // cout << i-1 << " " << ind << " " << j+1 << endl;
                    maxi = max(maxi, nums[i-1]*nums[ind]*nums[j+1]+ dp[i][ind-1] + dp[ind+1][j]);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
        // return f(1, n-2, nums, dp);
    }
};