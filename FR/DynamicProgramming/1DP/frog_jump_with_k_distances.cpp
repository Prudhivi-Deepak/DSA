class Solution {
public:
    // go to n to 0
    // if i > 1 we can do i-2 else no
    int f(int i, vector<int>& heights, int k, vector<int>& dp){

        if(i==0) return 0;

        if(dp[i]!=-1) return dp[i];

        // int step1 = abs(heights[i]-heights[i-1]) + f(i-1, heights, dp);
        int min_step = 1e9;

        for(int step=1; step<=k; step++){
            if(i-step>=0)
                min_step = min(abs(heights[i]-heights[i-step]) + f(i-step, heights, k, dp), min_step);
        }
        
        return dp[i] = min_step;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);

        // i goes from n to 0 in f ,
        // so here it goes from 0 to no
        // base case is i=0 dp[i] = 0
        // dp[0] = 0;

        for(int i=1; i<n; i++){
            int min_step = 1e9;

            for(int step=1; step<=k; step++){
                if(i-step>=0)
                    min_step = min(abs(heights[i]-heights[i-step]) + dp[i-step], min_step);
            }
            
            dp[i] = min_step;
        }
        return dp[n-1];
        // return f(n-1, heights, k, dp);
    }
};
