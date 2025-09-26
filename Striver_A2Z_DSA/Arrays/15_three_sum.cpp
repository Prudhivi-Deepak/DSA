#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            set<vector<int>> hashset;
    
            for(int i=0; i<nums.size(); i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
    
                int left = i+1, right = nums.size()-1;
                while(left<right){
                    int value = nums[i]+nums[left]+nums[right];
                    if(value == 0){
                        hashset.insert({nums[i],nums[left],nums[right]});
                        left++; right--;
                    }
                    else if(value < 0){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
    
            vector<vector<int>> result(hashset.begin(), hashset.end());
            return result;
        }
    };