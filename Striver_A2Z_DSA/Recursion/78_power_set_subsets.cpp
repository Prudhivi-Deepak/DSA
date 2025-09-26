#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void f(int i, int n,vector<int>& nums, vector<int> &oneset, vector<vector<int>> &ans){
            if(i==n){
                ans.push_back(oneset);
                return;
            }
    
            oneset.push_back(nums[i]);
            f(i+1, n, nums, oneset, ans);
            oneset.pop_back();
            f(i+1, n, nums, oneset, ans);
    
            return;
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> oneset;
            f(0, nums.size(), nums, oneset, ans);
            return ans;
        }
    };