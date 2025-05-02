#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int f(int i, vector<int>& nums, vector<int> &dp){
            if(i >= nums.size()-1) return 0;
            if(dp[i]!=-1) return dp[i];
            int mini = 10e4;
            for(int j=i+1; j<=nums[i]+i; j++){
                mini = min(mini, f(j,nums, dp));
            }
            return dp[i] = mini+1;
        }
        int jump(vector<int>& nums) {
            int n = nums.size(), maxReach = 0, currReach = 0, jumps = 0;
            for(int i=0; i<n; i++){
                if( maxReach >= n-1) return jumps;
                currReach = max(nums[i]+i, currReach);
                if(i==maxReach){
                    jumps++;
                    maxReach = currReach;
                }
            }
            return jumps;
    
            // vector<int> dp(n+1, 0);
            
            // for(int i=n-2; i>=0; i--){
            //     int mini = 10e4;
            //     for(int j=i+1; j<=nums[i]+i && j<n; j++){
            //         mini = min(mini, dp[j]);
            //     }
            //     dp[i] = mini+1;
            // }
            // return dp[0];
    
            // return f(0, nums, dp);
        }
    };