#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool IsDivisorInLimit(vector<int> &nums, int threshold, int divisor){
            int calculated_limit = 0;
            for(int i=0; i<nums.size(); i++){
                calculated_limit += ceil(1.0*nums[i]/divisor);
            }
            return calculated_limit<=threshold;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int left = 1, max_element = nums[0], mid;
            for(int i=1; i<nums.size(); i++){
                max_element = max(max_element, nums[i]);
            }
    
            while(left <= max_element){
                mid = left+(max_element-left)/2;
                if(IsDivisorInLimit(nums, threshold, mid)) max_element = mid-1;
                else left = mid+1;
            }
            return left;
        }
    };