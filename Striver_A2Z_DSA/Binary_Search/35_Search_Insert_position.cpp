#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
           int left = 0, right = nums.size()-1, mid;
           if(target < nums[left]) return 0;
           if(target > nums[right]) return right+1;
    
           while(left <= right){
                mid = left + (right-left)/2;
                if(target == nums[mid]) return mid;
                else if(target < nums[mid]) right = mid-1;
                else left = mid+1;
    
                if(left == right){
                    if(target <= nums[left]) return left;
                    else return left+1;
                }
            }
            return mid;
        }
    };