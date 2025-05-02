#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // unordered_map<int,int> umap;
            vector<int> hash(256, -1);
    
            int i=0, j=0, maxlen = j-i+1, n=s.size();
    
            if(n<2) return n;
    
            while(j<n){
    
                if(hash[s[j]] != -1){
                    if(hash[s[j]] >= i){
                        i = hash[s[j]]+1;
                    }
                    hash[s[j]] = j;
                }
                else{
                    hash[s[j]] = j;
                }
    
                maxlen = max(maxlen, j-i+1);
    
                j++;
            }
    
            return maxlen;
        }
    }; 