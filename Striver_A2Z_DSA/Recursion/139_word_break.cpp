#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
        bool IsTwoStringsEqual(string s1, string s2){
            int l1 = s1.size(), l2 = s2.size();
    
            if(l1!=l2) return false;
            int i=0;
            while(i<l1){
                 if(s1[i]!=s2[i]) return false;
                 i++;
            }
            return true;
        }
        bool f(int i, string s, set<string> &wordset, vector<int> &dp){
    
            if(i==s.size()) return dp[i] = true;
    
            if(dp[i]!=-1) return dp[i];
    
            for(auto Wordset : wordset){
                if( IsTwoStringsEqual(s.substr(i,Wordset.size()), Wordset) ){
                    if(f(i+Wordset.size(), s, wordset, dp)) return dp[i] = true;
                }
            }
    
            return dp[i] = false;
    
        }
        bool wordBreak(string s, vector<string>& wordDict) {
            set<string> wordset(wordDict.begin(), wordDict.end());
            // vector<int> dp(s.size()+1,-1);
    
            // bool ans = f(0, s, wordset, dp);
            // // cout << "---------" << endl;
            // for(int i=0; i<dp.size(); i++){
            //     cout << dp[i] << endl;
            //     dp[i]=0;
            // }
    
            int n = s.size();
            vector<bool> dp(n + 1, false);
    
            dp[n] = true; // Base case: empty suffix is always valid
    
            // Move from right to left, simulating recursion from index i
            for (int i = n - 1; i >= 0; i--) {
                for (const string& word : wordset) {
                    int len = word.size();
                    if (i + len <= n && s.substr(i, len) == word) {
                        if (dp[i + len]) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
    
            return dp[0];
    
            // return ans;
        }
    };