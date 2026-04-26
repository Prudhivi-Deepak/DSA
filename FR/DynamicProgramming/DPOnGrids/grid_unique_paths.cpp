class Solution {
public:
    // go from m-1, n-1 to 0, 0
    // we can move up(i, j-1) and left(i-1, j)
    int f(int i, int j, vector<vector<int>> &dp){

        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = f(i, j-1, dp) + f(i-1, j, dp);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));

        // iter 
        // we go from 0, 0 to m-1,n-1
        // base case is dp[0][0] = 1
        // dp[0][0] = 1;

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==0 && j==0) continue;
        //         dp[i][j] = (j-1>=0 ? dp[i][j-1] : 0) + (i-1>=0 ? dp[i-1][j] : 0);
        //     }
        // }

        // return dp[m-1][n-1];
        // return f(m-1, n-1, dp);

        // unique ways to get min(m-1,n-1) D or R from m+n-2 steps
        // ncr = n!/(n-r)! r!
        // 5c2 = 5 4 3 2 1    = 5 4
        //       2 1 * 3 2 1    1 2
        int N = m+n-2, R = min(m-1, n-1);
        long long ans = 1;
        for(int i=1; i<=R; i++){
            ans *= (N-i+1);
            ans /= i;
        }
        return (int)ans;
    }
};