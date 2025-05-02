#include<bits/stdc++.h>
using namespace std;

bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
   if(i==0 && j==0) return true;

   if(i==0 && j>0) return false;

   if(j==0 && i>0){
      for(int k=1; k<=i; k++){
         if(pattern[k-1]!='*') return false;
      }
      return true;
   }
   if(dp[i][j] != -1) return dp[i][j];
   if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);
   else{
      if(pattern[i-1] == '*'){
        return dp[i][j] = f(i-1, j, pattern, text, dp) || f(i, j-1, pattern, text, dp);
      }
      else{
         return dp[i][j] = false;
      }
   }
}

bool wildcardMatching(string pattern, string text){
   // Write your code here.
   int n = pattern.size();
   int m = text.size();
   // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
   vector<int> prev(m+1, 0), curr(m+1, 0);
   // dp[0][0] = 1;
   prev[0] = 1;
   for(int j=1; j<=m; j++) prev[j] = 0;

   for(int i=1; i<=n; i++){
      // dp[i][0] = 1;
      curr[0] = 1;
      for(int k=1; k<=i; k++){
         if(pattern[k-1]!='*'){
            curr[0] = 0;
            break;
         }
      }

      for(int j=1; j<=m; j++){
         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') 
            curr[j] = prev[j-1];
         else if(pattern[i-1] == '*'){
            curr[j] = prev[j] || curr[j-1];
         }
         else{
            curr[j] = 0;
         }
      }
      prev = curr;
   }
   return prev[m];
   // return f(n, m, pattern, text, dp);
   // return false;
}
