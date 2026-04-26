class Solution{
public:
    int f(int buyNow, int i, vector<int> arr, int n, vector<vector<int>> &dp, int fee){
        if(i>=n) return 0;

        if(dp[i][buyNow] != -1) return dp[i][buyNow];

        int notTake = f(buyNow, i+1, arr, n, dp, fee);
        int take = 0;
        if(buyNow){
            take = -arr[i] + f(!buyNow, i+1, arr, n, dp, fee);
        }
        else{
            take = arr[i] - fee + f(!buyNow, i+1, arr, n, dp, fee);
        }
        return dp[i][buyNow] = max(notTake, take);
    }

    int stockBuySell(vector<int> arr, int n, int fee){

        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> prev(2, 0), curr(2, 0);

        // in f i goes from 0 to n and buyNow 1 and 0
        // base case is i>=n return 0

        for(int i=n-1; i>=0; i--){
            for(int buyNow=1; buyNow>=0; buyNow--){
                // int notTake = dp[i+1][buyNow];
                int notTake = prev[buyNow];
                int take = 0;
                if(buyNow){
                    // take = -arr[i] + dp[i+1][!buyNow];
                    take = -arr[i] + prev[!buyNow];
                }
                else{
                    // take = arr[i] + dp[i+1][!buyNow];
                    take = arr[i] - fee + prev[!buyNow];
                }
                // dp[i][buyNow] = max(notTake, take);
                curr[buyNow] = max(notTake, take);
            }
            prev = curr;
        }
        // return dp[0][1];
        return prev[1];
        // return f(1, 0, arr, n, dp, fee);

    }
};

