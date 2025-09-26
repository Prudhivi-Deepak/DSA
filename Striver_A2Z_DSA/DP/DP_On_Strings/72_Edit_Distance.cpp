#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string str1, string str2) {
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
  
    int editDistanceFirstTry(string start, string target) {     
        // didn't work as replace is there   
        int n = start.size(), m = target.size();
        if(n==0) return m;
        if(m==0) return n;
        int P = lcs(start, target);
        cout << P << " : "  << n << " : " << m << endl;
        int l = n-P, r = m-P;
        return abs(l-r)+r;
    }
    int minDistance(string start, string target) {
        int n = start.size(), m = target.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j=1; j<=m; j++) prev[j] = j;
        // for(int j=1; j<=m; j++) dp[0][j] = j;
        // for(int i=1; i<=n; i++) dp[i][0] = i;

        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(start[i-1] == target[j-1]){
                    // dp[i][j] = dp[i-1][j-1];
                    curr[j] = prev[j-1];
                }
                else{
                    // dp[i][j] = 1+min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                    curr[j] = 1+min({curr[j-1], prev[j], prev[j-1]});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};