
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int curr_sum = nums[0], prev_start = 0, start_index =0, end_index = 0, max_sum = nums[0];
            for(int i=1; i<nums.size(); i++){
                if(curr_sum <0) {
                    start_index = i;
                    curr_sum = 0;
                }
                curr_sum += nums[i];
                if(max_sum < curr_sum){
                    prev_start = start_index;
                    end_index = i;
                    max_sum = max(max_sum, curr_sum);
                }
            }
            // cout << prev_start << " : " << end_index << endl;
            return max_sum;
            // int maxsum = INT_MIN, currsum = 0, min_value=INT_MIN;
            // for(int i:nums){
            //     currsum += i;
            //     maxsum = max(maxsum, currsum);
            //     if(currsum<0){
            //         currsum = 0;
            //     }
            // }
            // return maxsum;
        }
    };