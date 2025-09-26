#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int longestSubarray(vector<int> &nums, int k){
            unordered_map<int,int> umap;
            int max_count = 0, sum = 0;
            for(int i=0; i<nums.size(); i++){
                sum += nums[i];
                if(sum == k){
                    max_count = max(max_count, i+1);
                }
                else if(umap.find(sum-k)!=umap.end()){
                    max_count = max(max_count, i-umap[sum-k]);
                }
                
                if(umap.find(sum)==umap.end()){
                    umap[sum] = i;
                }
            }
            return max_count;
        }
    };
    