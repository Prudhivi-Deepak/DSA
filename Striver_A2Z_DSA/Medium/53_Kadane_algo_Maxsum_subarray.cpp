// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN, currsum = 0, all_neg=true, min_value=INT_MIN;
        for(int i:nums){
            // if(i>0){
            //     all_neg = false;
            // }
            // min_value = max(min_value, i);
            currsum += i;
            maxsum = max(maxsum, currsum);
            if(currsum<0){
                currsum = 0;
            }
        }
        // if(all_neg == true){
        //     return min_value;
        // }
        return maxsum;
    }
};