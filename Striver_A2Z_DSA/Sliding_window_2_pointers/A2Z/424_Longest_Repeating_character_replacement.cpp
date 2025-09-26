#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        // max character, other frequencies
        // if maxlen - maxfrequency > k means not a valid substring we are not able to convert this and not a longest string
        // else its a valid substring so take the longest substring

        int l = 0, r = 0, n = s.size(), max_freq = 0, max_len_substring = 0;

        unordered_map<char, int> umap;

        while(r<n){
            umap[s[r]]++;
            max_freq = max(max_freq, umap[s[r]]);

            if((r-l+1)-max_freq>k){
                umap[s[l]]--;
                if(umap[s[l]]==0) umap.erase(umap[s[l]]);
                l++;
            }
            else{
                max_len_substring = max(max_len_substring, r-l+1);
            }
            r++;
        }
        return max_len_substring;
    }
    int characterReplacementFirstTry(string s, int k) {
        unordered_map<int,int> umap;
        int i=0, j=0, maxlen=0;
        while(j<s.size()){
            umap[s[j]]++;
            if(umap.size()>1){
                if(k>0){
                    if(umap[s[i]]<=k){
                        k -= umap[s[i]];
                    }
                }
                else{
                    umap[s[i]]--;
                    i++;
                    if(umap[s[i]]==0) 
                        umap.erase(s[i]);
                    k++;
                }
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};