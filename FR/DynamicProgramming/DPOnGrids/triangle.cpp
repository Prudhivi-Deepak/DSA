class Solution {
public:
    // j from different 0 to m , i=n-1 --------> any i base case
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i>=triangle.size() || j>i|| i<0 || j<0) return 1e9;
        
        if(i==0) return triangle[i][j];

        if(dp[i][j] !=-1) return dp[i][j];

        int up = f(i-1, j, triangle, dp);
        int upLeft = f(i-1, j-1, triangle, dp);
        // int upRight = f(i-1, j+1, triangle, dp);

        return dp[i][j] = min({up, upLeft})+ triangle[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, 0));

        vector<int> prev(m, 0), curr(m, 0);

        // j from different 0 to m , i=n-1 --------> any i base case
        for(int j=0; j<m; j++){
            // dp[0][j] = triangle[0][j];
            prev[j] = triangle[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                // dp[i][j] = min({
                //     (i-1)>=0 ? dp[i-1][j] : 1e9, 
                //     ((i-1)>=0 && (j-1)>=0) ? dp[i-1][j-1] : 1e9, 
                //     ((i-1)>=0 && (j+1)<m) ? dp[i-1][j+1] : 1e9})  + triangle[i][j];

                int up = prev[j];
                int upLeft = ((i-1)>=0 && (j-1)>=0) ? prev[j-1] : 1e9;
                int upRight = ((i-1)>=0 && (j+1)<m) ? prev[j+1] : 1e9;

                curr[j] = min({
                    up, 
                    upLeft, 
                    upRight})  + triangle[i][j];
            }
            prev = curr;
        }

        int minPathSum = 1e9;
        for(int j=0; j<m; j++){
            // minPathSum = min(minPathSum, f(n-1, j, triangle, dp) );
            // minPathSum = min(minPathSum, dp[n-1][j]);
            minPathSum = min(minPathSum, prev[j]);
        }
        return minPathSum;
    }

    int minTriangleSum(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // vector<vector<int>> dp(n, vector<int>(n, 1e9));

        vector<int> prev(n, 1e9), curr(n, 1e9);

        // for(int j=0; j<n; j++){
        //     dp[0][j] = triangle[0][j];
        // }
        // dp[0][0] = triangle[0][0];
        prev[0] = triangle[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                // int up = dp[i-1][j];
                int up = prev[j];
                // int upLeft = (j-1>=0) ? dp[i-1][j-1] : 1e9;
                int upLeft = (j-1>=0) ? prev[j-1] : 1e9;
                // int upRight = f(i-1, j+1, triangle, dp);

                // dp[i][j] = min({up, upLeft})+ triangle[i][j];
                curr[j] = min({up, upLeft})+ triangle[i][j];
            }
            prev = curr;
        }

        int minPathSum = 1e9;
        for(int j=0; j<n; j++){
            // minPathSum = min(minPathSum, f(n-1, j, triangle, dp) );
            // minPathSum = min(minPathSum, dp[n-1][j]);
            minPathSum = min(minPathSum, prev[j]);
        }
        return minPathSum;
    }
};