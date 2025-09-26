#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int prefix_pro = 0, suffix_pro = 0, max_pro = INT_MIN;
    
            for(int i=0; i<nums.size(); i++){
    
                if(prefix_pro==0) prefix_pro=1;
                if(suffix_pro==0) suffix_pro=1;
    
                prefix_pro *= nums[i];
                suffix_pro *= nums[nums.size()-1-i];
    
                max_pro = max(max_pro, max(prefix_pro, suffix_pro));
    
            }
            return max_pro;
        }
    };