#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        int frogJump(vector<int>& heights) {
            int n = heights.size();
            vector<int> dp(n+1, 1e9);
            dp[n-1]=0;
            for(int i=n-2; i>=0; i--){
                int t1 = dp[i+1]+abs(heights[i]-heights[i+1]);
                int t2 = dp[i+2]+abs(heights[i]-heights[i+2]);
                dp[i] = min(t1, t2);
            }
            return dp[0];
        }
    };