#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> lcs(string str1, string str2) {
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
        return dp;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = lcs(str1, str2);
        string superSeq = "";

        int i = str1.size()-1, j = str2.size()-1;

        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
                superSeq += str1[i]; i--; j--;
            }
            else{
                int l = (j-1>=0) ? dp[i][j-1] : -1, u = (i-1>=0) ? dp[i-1][j] : -1;
                if(l>u){
                    superSeq += str2[j]; j--;
                }
                else{
                    superSeq += str1[i]; i--;
                }
            }
        }

        while(i>=0){
            superSeq += str1[i]; i--;
        }

        while(j>=0){
            superSeq += str2[j]; j--;
        }

        // cout << superSeq << endl;
        reverse(superSeq.begin(), superSeq.end());

        return superSeq;
    }
};