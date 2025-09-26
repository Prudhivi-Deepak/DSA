#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
   int f(int i, vector<int> &nums, int prev, vector<vector<int>> &dp){
        if(i==0){
            if(prev==nums.size()) return 1;
            if (prev < nums.size()) return nums[prev] > nums[0] ? 1 : 0;
        }

        if(dp[i][prev]!=-1) return dp[i][prev];

        int NT = f(i-1, nums, prev, dp);
        int T = (prev==nums.size() || nums[prev] > nums[i]) ? 1+f(i-1, nums, i, dp) : 0;
        
        
        return dp[i][prev] = max(NT, T);

    }


    vector<int> longestIncreasingSubsequence(vector<int>& nums) {
        // print lis
        int n = nums.size();
        vector<int> dp(n+1, 1), parent(n+1, 0);
        int lis_index = 0;

        for(int i=0; i<n; i++){
            parent[i] = i;
            for(int p=0; p<i; p++){
                if(nums[p]<nums[i] && dp[i] < 1+dp[p] ) {
                    dp[i] = 1+dp[p];
                    parent[i] = p;
                }
            }
            // cout << dp[i] << " ";

            if(dp[i]>dp[lis_index]){
                lis_index = i;
            }
        }

        // cout << endl;

        // for(int i=0; i<n; i++){
        //     cout << parent[i] << " ";
        // }

        // cout << endl;
        // cout << lis_index << parent[lis_index] << endl;

        vector<int> LIS;

        while(lis_index!=parent[lis_index]){
            LIS.push_back(nums[lis_index]);
            lis_index = parent[lis_index];
        }
        LIS.push_back(nums[lis_index]);

        reverse(LIS.begin(), LIS.end());


        // for(auto i: LIS){
        //     cout << i << "-";
        // }
        // cout << endl;


        return LIS;
    }

    vector<int> longestIncreasingSubsequenceAnalysis(vector<int>& nums) {
         int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int p=i; p>=0; p--){
                // int NT = dp[i+1][p];
                // int T = (p==0 || nums[i]>nums[p-1]) ? 1+dp[i+1][i+1]:0;

                // int T = 0;
                // if(p==0 || nums[i]>nums[p-1]){
                //     T = 1+dp[i+1][i+1];
                // }
                // dp[i][p] = max(NT, T);

                // int NT = next[p];
                // int T = (p==0 || nums[i]>nums[p-1]) ? 1+next[i+1]:0;

                int lis_row =  next[p];
                if(p==0 || nums[i]>nums[p-1]){
                    if(lis_row < 1+next[i+1]){
                        lis_row = 1+next[i+1];
                    }
                }
                // curr[p] = max(NT, T);
                curr[p] = lis_row;
            }
            next = curr;
            cout << next[0] << " ";
        }
        cout << endl;

        for(int i=0; i<n; i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        // for(int i=n-1; i>=0; i--){
        //     cout << dp[i][0] << " ";
        // }

        // cout << endl;
        // cout << endl;

        // for(int i=n-1; i>=0; i--){
        //     cout << nums[i] << " : ";
        //     for(int j=n-1; j>=0; j--){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // return dp[0][0];

        return {};
    }
};