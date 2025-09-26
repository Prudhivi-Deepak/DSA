#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            long target = 0;
            for(int i: nums){
                target += i;
            }
    
            if(target%2==1) return false;
    
            target /= 2;
    
            // int n = nums.size();
            // vector<vector<bool>> dp(n, vector<bool>(target+1, false));
            vector<bool> prev(target+1, false), curr(target+1, false);
            // for(int i=0; i<n; i++){
            //     dp[i][0] = true;
            // }
            prev[0] = true;
    
            // if(nums[0] <= target) dp[0][nums[0]] = true;
            if(nums[0] <= target) prev[nums[0]] = true;
    
            for(int i=1; i<n; i++){
                for(int t=0; t<=target; t++){
                    // bool NT = dp[i-1][t];
                    // bool T = t>=nums[i] ? dp[i-1][t-nums[i]] : false;
                    bool NT = prev[t];
                    bool T = t>=nums[i] ? prev[t-nums[i]] : false;
                    curr[t] = NT||T;
                }
                prev = curr;
            }
            return prev[target];
        }
    };