#include <bits/stdc++.h>

using namespace std;

class Solution {

// int f(int ind, int last_ind, vector<int>& nums){
    // if(ind == 0){
    //     if(last_ind == 1e9) return 1;
    //     if(nums[ind] >= nums[last_ind]) return 0;
    //     else return 1;
    // }
    // if(last_ind == 1e9){
    //     if(nums[ind] < last_ind){
    //         return max(1+f(ind-1, ind, nums), 0+f(ind-1, last_ind, nums));
    //     }
    //     else{
    //         return f(ind-1, last_ind, nums);
    //     }
    // }
    // if(nums[ind] < nums[last_ind]){
    //     return max(1+f(ind-1, ind, nums), 0+f(ind-1, last_ind, nums));
    // }
    // else{
    //     return f(ind-1, last_ind, nums);
    // }
// }

int f1(int ind, int prev, int n, vector<int>& nums, vector<vector<int>> &dp){

    if(ind == n-1){
        if(prev == -1 || nums[prev] < nums[ind]) return dp[ind][prev+1] = 1;
        else return dp[ind][prev+1]= 0;
    }
    
    if (dp[ind][prev+1] != -1) return dp[ind][prev+1];

    if(prev==-1 || nums[prev]<nums[ind])
        return dp[ind][prev+1] = max(1+f(ind+1, ind, n, nums, dp), 0+f(ind+1, prev, n, nums, dp));
    else
        return dp[ind][prev+1] = 0+f(ind+1, prev, n, nums, dp);
}

int f(int ind, int prev, int n, vector<int>& nums, vector<vector<int>> &dp){

    if(ind == n-1){
        if(prev == 0 || nums[prev-1] < nums[ind]) return dp[ind][prev] = 1;
        else return dp[ind][prev]= 0;
    }
    
    if (dp[ind][prev] != -1) return dp[ind][prev];

    if(prev==0 || nums[prev-1]<nums[ind])
        return dp[ind][prev] = max(1+f(ind+1, ind+1, n, nums, dp), 0+f(ind+1, prev, n, nums, dp));
    else
        return dp[ind][prev] = 0+f(ind+1, prev, n, nums, dp);
}

public:
    int lengthOfLIS(vector<int>& nums) {
        // return f(nums.size()-1, 1e9, nums);
        int n = nums.size();
        // // vector<vector<int>> dp(n, vector<int>(n+1, 0));
        // vector<int> prev_dp(n+1, 0);
        // for(int prev=0; prev<=n; prev++)
        //     if(prev == 0 || nums[prev-1] < nums[n-1]) 
        //         prev_dp[prev] = 1;
        // for(int ind=n-2; ind>=0; ind--){
        //     for(int prev=0; prev<=n; prev++){
        //         if(prev==0 || nums[prev-1]<nums[ind])
        //             prev_dp[prev] = max(1+prev_dp[ind+1], prev_dp[prev]);
        //         // else
        //         //     prev_dp[prev] = prev_dp[prev];
        //         // cout << dp[ind][prev] << " ";

        //         if(ind==0) return prev_dp[0];
        //     }
        //     // prev_dp = curr_dp;
        //     // cout << endl;
        // }
        // return prev_dp[0];
        // // return f(0, 0, n, nums, dp);
    // ------------------------------------------------
        vector<int> dp(n, 1);

        // 0  1 2 3 4 5  6  7
        // 10 9 2 5 3 7 101 18
        // 1  1 1 1 1 1  1   1
    // 1// 1  1 1 2 2 2
    //                3
    //                3

        // int maxi = 1;

        // for(int ind=1; ind<n; ind++){
        //     int temp = dp[ind];
        //     for(int i=0; i<ind; i++){
        //         if(nums[i]<nums[ind]){
        //             dp[ind] = max(temp+dp[i], dp[ind]);
        //         }
        //     }
        //     maxi = max(maxi, dp[ind]);
        // }
        // return maxi;
    // ------------------------------------------------------
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int ind=1; ind<n; ind++){
            if(temp.back() < nums[ind]){
                temp.push_back(nums[ind]);
            }
            else{
                auto i = lower_bound(temp.begin(), temp.end(), nums[ind]);
                if(i!=temp.end()) *i = nums[ind];
            }
        }

        return temp.size();

    }
};

// 1 7 8 4 5 6 -1 9

//1
// 1 7
//  1 7 8
// 4 //  
// 1 4 8
// 5 //
//  1 4 5
// 6 //
// 1 4 5 6
// -1 //
//  -1 4 5 6
// 9 //
// -1 4 5 6 9

