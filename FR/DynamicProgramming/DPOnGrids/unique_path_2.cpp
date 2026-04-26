class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){

        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(matrix[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = f(i, j-1, matrix, dp) + f(i-1, j, matrix, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(matrix[0][0] || matrix[m-1][n-1]) return 0;
        if(m==1 && n==1) {
            return !matrix[0][0];
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));

        vector<int> prev(n, 0), curr(n, 0);

        // iter 
        // we go from 0, 0 to m-1,n-1
        // base case is dp[0][0] = 1
        // dp[0][0] = 1;
        curr[0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                if(matrix[i][j]==1) {
                    // dp[i][j] = 0;
                    curr[j] = 0;
                }
                else{
                    // dp[i][j] = (j-1>=0 ? dp[i][j-1] : 0) + (i-1>=0 ? dp[i-1][j] : 0);
                    curr[j] = (j-1>=0 ? curr[j-1] : 0) + (i-1>=0 ? prev[j] : 0);
                }
            }
            prev = curr;
        }

        return prev[n-1];

        // return f(m-1, n-1, matrix, dp);
    }
};