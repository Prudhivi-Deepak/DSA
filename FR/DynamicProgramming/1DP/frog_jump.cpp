class Solution {
public:
    // go to n to 0
    // if i > 1 we can do i-2 else no
    int f(int i, vector<int>& heights, vector<int>& dp){

        if(i==0) return 0;

        if(dp[i]!=-1) return dp[i];

        int step1 = abs(heights[i]-heights[i-1]) + f(i-1, heights, dp);
        int step2 = 1e9;
        if(i>1) 
            step2 = abs(heights[i]-heights[i-2]) + f(i-2, heights, dp);
        
        return dp[i] = min(step1, step2);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);

        // i goes from n to 0 in f ,
        // so here it goes from 0 to no
        // base case is i=0 dp[i] = 0
        dp[0] = 0;

        for(int i=1; i<n; i++){
            int step1 = abs(heights[i]-heights[i-1]) + dp[i-1];
            int step2 = 1e9;
            if(i>1) 
                step2 = abs(heights[i]-heights[i-2]) + dp[i-2];
            
            dp[i] = min(step1, step2);
        }
        return dp[n-1];
        // return f(n-1, heights, dp);
    }
};