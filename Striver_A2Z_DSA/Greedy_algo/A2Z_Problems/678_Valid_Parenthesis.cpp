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
        //your code goes here
        // ( ==> +1 ) ==> -1 * ==> -1 0 +1

        // (*)) ==> curr = 0
        // (min, max) = (0, 0) curr = 0
        // ( max+e = 0+1 = 1 => (0, 1)
        // * max+e = 1+0, 1+1, 1-1 
        //         = 1, 2, 0 => (0, 2)
        // ) max+e = 2-1 = 1 => (0, 1)
        // ) max+e = 1-1 = 0 => (0, 0)
        // valid range = min<=0<=max

        // ( = 1  curr = 0+1 = 1 ==> (0, 1)
        // ) = -1 curr = 1-1 = 0 ==> (0, 0)
        // * = 0 1 -1 curr = 0+0, 0+1, 0-1 
        //                 = 0, 1, -1 ==> (0, 1)

        // *(()
        // * = 0, 1, -1 = (0, 1)
        // ( = 1+1 = 2 = (0, 2)
        // ( = 2+1 = 3 = (0, 3)
        // ) = 3-1 = 2 = (0, 2)
        
        int min_e = 0, max_e = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                min_e++; max_e++;
            }
            else if(s[i]==')'){
                min_e--; max_e--;
            }
            else{
                min_e--;
                max_e++;
            }
            if(min_e<0) min_e = 0;
            if(max_e<0) return false;
            // cout << s[i] << " : " << min_e << " : " << max_e << endl;
        }
        return min_e == 0;
    }

    bool checkValidStringFirstTry(string s) { 
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