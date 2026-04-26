class Solution{
    public:
        int f(int i, int remW, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
            if(i==0){
                if(remW>=wt[0]) return val[0];
                else return 0;
            }

             if(dp[i][remW]!=-1) return dp[i][remW];

            int NotTake = f(i-1, remW, wt, val, dp);
            int Take = 0;
            if(remW>=wt[i]) Take = val[i] + f(i-1, remW-wt[i], wt, val, dp);

            return dp[i][remW] = max(NotTake, Take);
        }

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
             //your code goes here
            vector<vector<int>> dp(n, vector<int>(W+1, 0));
            // i goes from n-1 to 0 in f 
            // base case : for all weights if > wt[0] dp[0][remW] = val[0];

            for(int remW=wt[0]; remW<=W; remW++){
                dp[0][remW] = val[0];
            }

            for(int i=1; i<n; i++){
                for(int remW=0; remW<=W; remW++){

                    int NotTake = dp[i-1][remW];
                    int Take = 0;
                    if(remW>=wt[i]) Take = val[i] + dp[i-1][remW-wt[i]];

                    dp[i][remW] = max(NotTake, Take);
                }
            }

            return dp[n-1][W];
            // return f(n-1, W, wt, val, dp);
        }
};