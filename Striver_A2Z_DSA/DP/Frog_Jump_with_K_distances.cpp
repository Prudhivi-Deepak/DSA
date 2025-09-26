#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int frogJump(vector<int>& heights, int k) {
            int n = heights.size();
            vector<int> dp(n+1, 1e4); dp[n-1] = 0;
            for(int i=n-2; i>=0; i--){
                int min_ene = 1e4;
                for(int j=i+1; j<=i+k && j<n; j++){
                    min_ene = min(min_ene, dp[j] + abs(heights[i]-heights[j]));
                }
                dp[i] = min_ene;
            }
            return dp[0];
        }
    };
    