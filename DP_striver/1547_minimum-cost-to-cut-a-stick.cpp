#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind=i; ind<=j; ind++){
            mini = min(mini, cuts[j+1]-cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp));
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        for(int i=c-2; i>=1; i--){
            for(int j=1; j<=c-2; j++){
                if(i>j) continue;
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++){
                    mini = min(mini, cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
        // return f(1, cuts.size()-2 , cuts, dp);
    }
};