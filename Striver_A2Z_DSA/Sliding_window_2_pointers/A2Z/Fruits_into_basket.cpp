#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        // your code goes here

        // 1 2 3 2 2

        // 1 : 1 (0,0), 1
        // 1 : 1, 2 : 2 (0,1), 3
        // 1 : 1, 2 : 2, 3 : 1 (0,2), 3
        // 2 : 2, 3 : 1 (1,2), 3
        // 2 : 3, 3 : 1 (1,2), 4

        int max_fruits = 0, l = 0, r = 0, n = fruits.size();
        unordered_map<int, int> umap;

        while (r < n) {
            umap[fruits[r]]++;
            if(umap.size()>2){
              umap[fruits[l]]--;
              if(umap[fruits[l]]==0) umap.erase(fruits[l]);
              l++;
            }
            else{
              max_fruits = max(max_fruits, r-l+1);
            }
            r++;
        }
        return max_fruits;
    }
};