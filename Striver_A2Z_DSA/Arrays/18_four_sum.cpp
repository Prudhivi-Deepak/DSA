
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            set<vector<int>> hashset;
    
            for(int j=0; j<nums.size(); j++){
                if(j>0 && nums[j]==nums[j-1]) continue;
                for(int i=j+1; i<nums.size(); i++){
                    if(i>j+1 && nums[i]==nums[i-1]) continue;
    
                    int left = i+1, right = nums.size()-1;
                    while(left<right){
                        long long value = (long long)nums[j]+nums[i]+nums[left]+nums[right];
                        if(value == target){
                            hashset.insert({nums[j],nums[i],nums[left],nums[right]});
                            left++; right--;
                        }
                        else if(value < target){
                            left++;
                        }
                        else{
                            right--;
                        }
                    }
                }
            }
    
            vector<vector<int>> result(hashset.begin(), hashset.end());
            return result;
        }
    };