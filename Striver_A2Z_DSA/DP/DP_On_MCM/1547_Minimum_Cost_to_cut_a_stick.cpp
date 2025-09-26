#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int l, int r, vector<int>& cuts, vector<vector<int>> &dp){
        if(l+1==r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];
        
        int minimum_cuts = 1e9;

        for(int k=l+1; k<r; k++){
            minimum_cuts = min(minimum_cuts,
                cuts[r]-cuts[l]+ f(l, k, cuts, dp)+ f(k, r, cuts, dp)
            );
        }
        return dp[l][r] = minimum_cuts;
    }

    int firsttry(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind=i; ind<=j; ind++){
            mini = min(mini, cuts[j+1]-cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp));
        }
        return dp[i][j] = mini;
    }

public:
    //Revision
    int minCost(int n, vector<int>& cuts){
        //your code goes here
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
    
        vector<vector<int>> dp(m+1, vector<int>( m+1, 0));

        for(int l = m-1;l>=0; l--){
            for(int r=l+2; r<m; r++){
                // if(l>r || l+1==r) continue;
                int minimum_cuts = 1e9;
                for(int k=l+1; k<r; k++){
                    minimum_cuts = min(minimum_cuts,
                        cuts[r]-cuts[l]+ dp[l][k]+ dp[k][r]
                    );
                }
                dp[l][r] = minimum_cuts;
            }
        }
        return dp[0][m-1];

        // return f(0, cuts.size()-1, cuts, dp);
    }


    int minCostFirstTry(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        vector<int> prev(c, 0), curr(c, 0);

        for(int i=c-2; i>=1; i--){
            for(int j=1; j<=c-2; j++){
                if(i>j) continue;
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++){
                    mini = min(mini, cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j]);
                    // mini = min(mini, cuts[j+1]-cuts[i-1] + curr[ind-1] + prev[j]);
                }
                dp[i][j] = mini;
                cout << dp[i][j] << " ";
                // curr[j] = mini;
                // cout << curr[j] << " ";
            }
            // prev=curr;
            cout << endl;
        }

        return dp[1][c-2];
        // return prev[c-2];
        // return f(1, cuts.size()-2 , cuts, dp);
        
    }
};