class Solution {
public:

    //  i goes from n-1 to 0
    int f(int i, vector<int>& nums, vector<int> &dp){
        //  take i --> should not take i+1, go to i+2
        // not take i --> may or may not take i+1

        // if(i==0) return nums[0];
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        int notTake = f(i-1, nums, dp);
        int take = nums[i] + f(i-2, nums, dp);

        return dp[i] = max(take, notTake);
    }

    int nonAdjacent(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+2, -1);

        // i goes from o to n-1 in for loop here
        // base case is dp[0] = nums[0];
        // dp[0] = nums[0];
        // i<0 is nothing but we took n+1 so dp[0] whihc is 0 here

        for(int i=0; i<n; i++){
            
            int notTake = i-1<0 ? 0 : dp[i-1];
            int take = nums[i] + (i-2<0 ? 0 : dp[i-2]);

            dp[i] = max(take, notTake);
        }
        return dp[n-1];

        // return f(n-1, nums, dp);
    }
};