#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
         //your code goes here

        // A:1, B:1, c:1
        // ADOBECODEBANC

        // unordered_map<int, int> umap;
        int umap[256] = {0};

        for(int i=0; i<t.size(); i++) umap[t[i]]++;

        int l = 0, r = 0, n = s.size(), count = 0, index = -1, substring_count = 2*s.size();

        while(r<n){

            if(umap[s[r]]>0) count++;
            umap[s[r]]--;

            while(count == t.size()){
                // index = l;
                // substring_count = min(substring_count, r-l+1);

                if(r-l+1 < substring_count){
                    substring_count = r-l+1;
                    index = l;
                }

                umap[s[l]]++;
                if(umap[s[l]]==1) count--;

                l++;
                // cout << index << " : " << substring_count << endl;
            }
            r++;
        }
        // cout << index << " : " << substring_count << endl;
        if(index==-1) return "";
        return s.substr(index , substring_count);
    }

};