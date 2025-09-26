#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        
        // return length longest substring with <=k disctinct characters
        

        int max_s = 0, l = 0, r = 0, n = s.size();
        unordered_map<char, int> umap;

        while (r < n) {
            umap[s[r]]++;
            if(umap.size()>k){//>2 in s baskets
              umap[s[l]]--;
              if(umap[s[l]]==0) umap.erase(s[l]);
              l++;
            }
            else{
              max_s = max(max_s, r-l+1);
            }
            r++;
        }
        return max_s;
   }
};