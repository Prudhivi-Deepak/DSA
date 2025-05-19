#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size()-1;
    
            while(left <= right){
                int mid = left+(right-left)/2;
                // cout << left << " " << right << endl;
                // cout << mid << endl;
                if(nums[mid] == target) return mid;
                else if (nums[left] <= nums[mid]){// left part is sorted
                    //check for range in left part if yes search i left part
                    if(nums[left] <= target  && target < nums[mid])
                        right = mid-1;                
                    else
                        left = mid+1;
                }
                else{// right part is sorted
                    //search for range in right part if yes search in right part
                    if(nums[mid] < target  && target <= nums[right])
                        left = mid+1;                
                    else
                        right = mid-1;
                }
            }
            return -1;
        }
    };