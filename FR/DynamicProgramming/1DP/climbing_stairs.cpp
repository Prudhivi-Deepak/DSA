class Solution {
public:

    int f(int i, int n, vector<int> &dp){
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];

        int step1 = f(i+1, n, dp);
        int step2 = f(i+2, n, dp);

        return dp[i] = step1+step2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+2, 0);
        // return f(0, n, dp);

        // i goes from 0 to n
        // for goes from n to 0
        // base case = dp[n] = 1
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            int step1 = dp[i+1];
            int step2 = dp[i+2];
            dp[i] = step1+step2;
        }
        return dp[0];
    }
};