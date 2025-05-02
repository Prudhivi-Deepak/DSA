#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool compare(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n-m == 1){
            int i=0, j=0;
            while(i<n){
                if(j<m && s1[i]==s2[j]){
                    i++;j++;
                }else{
                    i++;
                }
            }
            if(i==n && j==m) return true;
        }
        return false;
    }
    
    bool static comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    public:
        int longestStrChain(vector<string>& words) {
    
            sort(words.begin(), words.end(), comp);
            int n = words.size(), maxi=1;
            vector<int> dp(n, 1);
            for(int ind=1; ind<n; ind++){
                for(int i=0; i<ind; i++){
                    // len s1 - len s2 = 1
                    // cout << words[ind] << " " << words[i] << " " << compare(words[ind], words[i]) << endl;
                    if(compare(words[ind], words[i]) && 1+dp[i] > dp[ind]){
                        dp[ind] = 1+dp[i];
                    }
                }
                maxi = max(maxi, dp[ind]);
            }
            return maxi;
        }
    };