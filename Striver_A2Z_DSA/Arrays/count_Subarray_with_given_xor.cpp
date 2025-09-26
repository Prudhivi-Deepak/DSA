#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int subarraysWithXorK(vector<int> &nums, int k) {
            int XR = 0, i=0, count=0;
            unordered_map<int, int> umap;
            umap[0] = 1;
            while(i<nums.size()){
                XR ^= nums[i];
                if(umap[XR^k]>0){
                    count += umap[XR^k];
                }
                umap[XR]++;
                i++;
            }
            return count;
    
        }
    };