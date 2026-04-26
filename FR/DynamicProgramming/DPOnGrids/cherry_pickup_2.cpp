class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& matrix, vector<vector<vector<int>>> &dp){

        int n = matrix.size(), m = matrix[0].size();
        
        if(i<0 || j1<0 || j2<0 || i>=n || j1>=m || j2>=m) return 0;

        if(i==n-1){
            if(j1==j2) return matrix[i][j1];
            else return (matrix[i][j1] + matrix[i][j2]);   
        }

        if(dp[i][j1][j2] != -1 ) return dp[i][j1][j2];

        int cherry = max({
            f(i+1, j1, j2, matrix, dp),
            f(i+1, j1, j2-1, matrix, dp),
            f(i+1, j1, j2+1, matrix, dp),
            f(i+1, j1-1, j2, matrix, dp),
            f(i+1, j1-1, j2-1, matrix, dp),
            f(i+1, j1-1, j2+1, matrix, dp),
            f(i+1, j1+1, j2, matrix, dp),
            f(i+1, j1+1, j2-1, matrix, dp),
            f(i+1, j1+1, j2+1, matrix, dp),
        });

        if(j1==j2) cherry += matrix[i][j1];
        else cherry += (matrix[i][j1] + matrix[i][j2]);

        return dp[i][j1][j2] = cherry;
    }

    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1==j2){
                    dp[n-1][j1][j2] = matrix[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int cherry = 0;

                    for(int d1=-1; d1<2; d1++){
                        for(int d2=-1; d2<2; d2++){
                            int dj1 = j1+d1, dj2 = j2+d2;

                            if(dj1>=0 && dj1<m && dj2>=0 && dj2<m){
                                cherry = max(cherry, dp[i+1][dj1][dj2]);
                            }
                        }
                    }

                    if(j1==j2) cherry += matrix[i][j1];
                    else cherry += (matrix[i][j1] + matrix[i][j2]);

                    dp[i][j1][j2] = cherry;
                }
            }
        }
        // int maxCherry = 0;
        // for(int j1=0; j1<m; j1++){
        //     for(int j2=0; j2<m; j2++){
        //         maxCherry = max(maxCherry, dp[n-1][j1][j2]);
        //     }
        // }

        return dp[0][0][m-1];
    }
};