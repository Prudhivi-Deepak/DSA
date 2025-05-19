#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int left = 0, n = nums.size(), right = n-1, mid, first_index;
    
            if(n==1) return nums[0];
            if(nums[0] != nums[1]) return nums[0];
            if(nums[n-1] != nums[n-2]) return nums[n-1];
    
            while(left <= right){
                mid = left + (right-left)/2;
    
                if(mid!=0 && mid!=n-1){
                    if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
                    else if(nums[mid-1] == nums[mid])
                        first_index = mid-1;
                    else if(nums[mid] == nums[mid+1])
                        first_index = mid;
    
                    if(first_index%2==0) left = mid+1;
                    else right = mid-1;
                }
            }
            return -1;
        }
    };