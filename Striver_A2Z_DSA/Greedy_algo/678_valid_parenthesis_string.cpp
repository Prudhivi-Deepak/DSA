
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool f(string s, int i, int ans, vector<vector<int>> &dp) {
            if( ans<1 ) return false;
            if (i == s.size())
                return ans == 1;
            if (dp[i][ans] != -1) return dp[i][ans];
    
            if (s[i] == '(') {
                return f(s, i + 1, ans + 1, dp);
            } else if (s[i] == ')') {
                return f(s, i + 1, ans - 1, dp);
            }
    
            return dp[i][ans] = f(s, i + 1, ans, dp) || f(s, i + 1, ans + 1, dp) ||
                    f(s, i + 1, ans - 1, dp);
        }
        bool checkValidString(string s) { 
            int n = s.size();
    
            // range of min and max
            int min = 0, max = 0;
    
            for(auto s1: s){
                if(s1=='('){
                    min++; max++;
                }
                else if(s1==')'){
                    if(min>=1) min--;
                    max--;
                }
                else{
                    if(min>=1) min--;
                    max++;
                }
                if(max<0) return false;
            }
    
            // cout << min << " :" << max << endl;
            return min<=0;
    
            // vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
    
            // vector<int> prev(n+2, 0), curr(n+2, 0);
            // for(int ans=1; ans<=n+1; ans++){
            //     prev[1] = 1;
            // }
            // for(int i=n-1; i>=0; i--){
            //     for(int ans=1; ans<n+1; ans++){
            //         if (s[i] == '(') {
            //             curr[ans] = prev[ans + 1];
            //         } else if (s[i] == ')') {
            //             curr[ans] = prev[ans - 1];
            //         }
            //         else{
            //             curr[ans] = prev[ans] || prev[ans + 1] || prev[ans - 1];
            //         }
            //     }
            //     prev = curr;
            // }
            // return prev[1]==1;
    
    
    
            // return f(s, 0, 1, dp); 
        }
    };