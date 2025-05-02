#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);
        int maxsum = 0;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(matrix[i-1][j-1] == 1){
                    // dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                    curr[j] = min(min(prev[j], curr[j-1]), prev[j-1])+1;
                }
                else{
                    curr[j]=0;
                }
                maxsum += curr[j];
            }
            prev = curr;
        }

        return maxsum;
    }
};