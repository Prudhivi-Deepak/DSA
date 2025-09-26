#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> prev(m, 0), curr(m, 0);

        // dp[0][0] = (str1[0] == str2[0])? 1 : 0;
        curr[0] = prev[0] = (str1[0] == str2[0])? 1 : 0;

        for(int ind1=0; ind1<n; ind1++){
            for(int ind2=0; ind2<m; ind2++){
                if(ind1==0 && ind2==0) continue;
                if(str1[ind1]==str2[ind2]){
                    // dp[ind1][ind2] = ((ind1>0 && ind2>0) ? dp[ind1-1][ind2-1] : 0) + 1;
                    curr[ind2] = ((ind1>0 && ind2>0) ? prev[ind2-1] : 0) + 1;
                }
                else{
                    curr[ind2] = max( (ind1>0 ? prev[ind2] : 0), (ind2>0 ? curr[ind2-1] : 0 ));
                }
            }
        }
        return prev[m-1];
    }
    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[0][0] = (str1[0] == str2[0])? 1 : 0;

        for(int ind1=0; ind1<n; ind1++){
            for(int ind2=0; ind2<m; ind2++){
                if(ind1==0 && ind2==0) continue;
                if(str1[ind1]==str2[ind2]){
                    dp[ind1][ind2] = ((ind1>0 && ind2>0) ? dp[ind1-1][ind2-1] : 0) + 1;
                }
                else{
                    dp[ind1][ind2] = max( (ind1>0 ? dp[ind1-1][ind2] : 0), (ind2>0 ? dp[ind1][ind2-1] : 0 ));
                }
            }
        }
        return dp[n-1][m-1];
    }
};