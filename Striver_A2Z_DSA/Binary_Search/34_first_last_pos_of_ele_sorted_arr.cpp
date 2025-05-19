#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = 0, right = nums.size()-1, min_I=-1, max_I=-1, mid;
    
            //to find the min index
            while(left<=right){
                mid = left + (right-left)/2;
    
                if(target == nums[mid]){
                    max_I = mid;
                    left = mid+1;
                }
                else if(target > nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
    
            left = 0, right = nums.size()-1;
            while(left<=right){
                mid = left + (right-left)/2;
    
                if(target == nums[mid]){
                    min_I = mid;
                    right = mid-1;
                }
                else if(target > nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
    
            return vector<int>{min_I, max_I};
        }
    };