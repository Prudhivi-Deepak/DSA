#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void f(int i, vector<int> &temp_store, vector<vector<int>> &result, vector<int>& nums){
    
            if(i==nums.size()){
                result.push_back(temp_store);
                return;
            }
    
            temp_store.push_back(nums[i]);
            f(i+1, temp_store, result, nums);
            temp_store.pop_back();
    
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
            f(i+1, temp_store, result, nums);
    
            return;
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            vector<int> temp_store;
    
            f(0, temp_store, result, nums);
    
            return result;
        }
    };