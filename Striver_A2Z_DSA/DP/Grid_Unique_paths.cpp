#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // vector<vector<int>> dp(m, vector<int>(n, 0));
    
            vector<int> sdp(n, 0), currdp(n, 0);
            sdp[0]=1; currdp[0]=1;
            // dp[0][0] =1;
    
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    currdp[j] = sdp[j] + currdp[j-1];
                }
                sdp = currdp;
            }
    
            return currdp[n-1];
        }
    };