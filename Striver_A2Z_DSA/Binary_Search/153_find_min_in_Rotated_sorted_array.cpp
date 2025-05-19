#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();
            int left = 0, right = n-1, mid;
    
            while(left <= right){
                mid = left+(right-left)/2;
                if(mid!=0 && mid!=n-1){
                    if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]) return nums[mid];
                    if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return nums[mid+1];
                }
                
                if(nums[mid] < nums[right]) right = mid-1;
                else left = mid+1;
            }
            return nums[mid];
        }
    };