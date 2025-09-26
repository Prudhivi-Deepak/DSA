#include<bits/stdc++.h>
using namespace std;

class Solution {

int firstTry(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
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
    int f(int l, int r, vector<int>& nums, vector<vector<int>> &dp){
        if(l+1==r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int maximum_coins = -1e9;

        for(int k=l+1; k<r; k++){
            maximum_coins = max(maximum_coins,
                nums[l]*nums[k]*nums[r] + f(l, k, nums, dp) + f(k, r, nums, dp)
            );
        }
        return dp[l][r] = maximum_coins;

    }
    int maxCoins(vector<int>& nums){
        //your code goes here
        //  1 3 1 5 8 1
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int m = n+2;

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int l=m-1; l>=0; l--){
            for(int r=l+2; r<m; r++){
                int maximum_coins = -1e9;
                for(int k=l+1; k<r; k++){
                    maximum_coins = max(maximum_coins,
                        nums[l]*nums[k]*nums[r] + dp[l][k] + dp[k][r]
                    );
                }
                dp[l][r] = maximum_coins;
            }
        }
        return dp[0][m-1];

        // return f(0, m-1, nums, dp);
    }
    int maxCoinsFirstTry(vector<int>& nums) {
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