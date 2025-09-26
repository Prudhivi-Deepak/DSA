#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrayAtmostK(vector<int>& nums, int k){
        int l = 0, r = 0, n = nums.size(), sum = 0, subarr_cnt = 0;
        // [1, 1, 0, 1, 0, 0, 1]

        while(r<n){
            sum += nums[r];
            while(l<n && sum >k){
                sum-=nums[l]; l++;
            }
            if(r >= l)subarr_cnt += (r-l+1);
            r++;
        }
        // cout << k << "  : " << subarr_cnt << endl;
        return subarr_cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //your code goes here

        // 1 1 0 1 0 0 1
        // sum = goal ==> return no. of subarrays with sum goal

        // subarrays with atmost sum 3
        // subarray(sum <= 3) - subarray(sum <= 2) = subarray(sum == 3)

        return numOfSubarrayAtmostK(nums, goal) - numOfSubarrayAtmostK(nums, goal-1);
    }
};