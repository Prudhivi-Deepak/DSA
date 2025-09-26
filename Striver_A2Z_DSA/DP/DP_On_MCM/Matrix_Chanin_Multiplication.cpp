#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
        int f(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
            if(i==j) return 0;

            if(dp[i][j]!=-1) return dp[i][j];

            int multiplications = 1e9;

            for(int k=i; k<j; k++){
                multiplications = min(multiplications, 
                    nums[i-1]*nums[k]*nums[j] + f(i, k, nums, dp) + f(k+1, j, nums, dp)
                );
            }
            return dp[i][j] = multiplications;
        }

		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));

            for(int i=n-1; i>0; i--){
                for(int j=i; j<n; j++){
                    if(i!=j){
                        int multiplications = 1e9;
                        for(int k=i; k<j; k++){
                            multiplications = min(multiplications, 
                                nums[i-1]*nums[k]*nums[j] + dp[i][k] + dp[k+1][j]
                            );
                        }
                        dp[i][j] = multiplications;
                    }
                }
            }

            return dp[1][n-1];

            // return f(1, nums.size()-1, nums, dp);
    	}
};