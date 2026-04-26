class Solution {
    public:
        // 1 3 1 5 8 1
        // 0 1 2 3 4 5

        // k = 1 2 3 4

        int f(int i, int j, vector<int>& nums, vector<vector<int>> &dp){

            if(i+1==j) return 0;

            if(dp[i][j]!=-1) return dp[i][j];

            int max_Coins = 0;
            for(int k=i+1; k<j; k++){
                max_Coins = max(max_Coins, nums[i]*nums[k]*nums[j] + f(i, k, nums, dp) + f(k, j, nums, dp));
            }

            return dp[i][j] = max_Coins;
        }

        int maxCoins(vector<int>& nums){
    	    //your code goes here
            nums.insert(nums.begin(), 1);
            nums.push_back(1);

            int n = nums.size();

            vector<vector<int>> dp(n, vector<int>(n, 0));

            // i j goes from 0 to n-1, i+2 to n-1
            // base case: 0

            for(int i=n-1; i>=0; i--){
                for(int j=i+2; j<n; j++){
                    int max_Coins = 0;
                    for(int k=i+1; k<j; k++){
                        max_Coins = max(max_Coins, nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
                    }
                    dp[i][j] = max_Coins;
                }
            }
            return dp[0][n-1];
            // return f(0, n-1, nums, dp);
        }
};