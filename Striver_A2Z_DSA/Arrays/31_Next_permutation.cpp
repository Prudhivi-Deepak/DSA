
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        void nextPermutation(vector<int>& nums) {
            int breakindex = -1;
            for(int i=nums.size()-2; i>=0; i--){
                if(nums[i] < nums[i+1]){
                    breakindex= i; break;
                }
            }
    
            if(breakindex==-1){
                reverse(nums.begin(), nums.end());
                return;
            }
    
            //now find a close greater value after breakindex;
            for(int i=nums.size()-1; i>breakindex; i--){
                if(nums[breakindex]<nums[i]){
                    swap(nums[breakindex], nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+breakindex+1, nums.end());
        }
    };