class Solution{
public:
    int f(int buyNow, int i, vector<int> arr, int n, int k, vector<vector<vector<int>>> &dp){
        if(i>=n || k<=0) return 0;

        if(dp[i][buyNow][k] != -1) return dp[i][buyNow][k];

        int notTake = f(buyNow, i+1, arr, n, k, dp);
        int take = 0;
        if(buyNow){
            take = -arr[i] + f(!buyNow, i+1, arr, n, k, dp);
        }
        else{
            take = arr[i] + f(!buyNow, i+1, arr, n, k-1, dp);
        }
        return dp[i][buyNow][k] = max(notTake, take);
    }

    int stockBuySell(vector<int> arr, int n, int K){
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(K+1, -1)));
        vector<vector<int>> prev(2, vector<int>(K+1, 0)), curr(2, vector<int>(K+1, 0));

        // in f i goes from 0 to n and buyNow 1 and 0
        // base case is i>=n return 0

        for(int i=n-1; i>=0; i--){
            for(int buyNow=1; buyNow>=0; buyNow--){
                for(int k=K; k>0; k--){
                    // int notTake = dp[i+1][buyNow][k];
                    int notTake = prev[buyNow][k];
                    int take = 0;
                    if(buyNow){
                        // take = -arr[i] + dp[i+1][!buyNow][k];
                        take = -arr[i] + prev[!buyNow][k];
                    }
                    else{
                        // take = arr[i] + dp[i+1][!buyNow][k-1];
                        take = arr[i] + prev[!buyNow][k-1];
                    }
                    // dp[i][buyNow][k] = max(notTake, take);
                    curr[buyNow][k] = max(notTake, take);
                }
            }
            prev = curr;
        }
        // return dp[0][1];
        return prev[1][K];
        // return f(1, 0, arr, n, K, dp);

    }
};
