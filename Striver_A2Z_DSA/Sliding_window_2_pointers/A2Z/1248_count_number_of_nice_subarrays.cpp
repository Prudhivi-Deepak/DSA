#include <bits/stdc++.h>
using namespace std;

class Solution {
public:int numOfSubarrayAtmostK(vector<int>& nums, int k){
        int l = 0, r = 0, n = nums.size(), curr_cnt = 0, subarr_cnt = 0;
        // [1, 1, 0, 1, 0, 0, 1]

        while(r<n){
            curr_cnt += nums[r]%2;
            
            while(l<n && curr_cnt>k){
                if(nums[l]%2==1) curr_cnt--;
                l++;
            }

            subarr_cnt += (r-l+1);
            
            r++;
        }
        // cout << k << "  : " << subarr_cnt << endl;
        return subarr_cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //your code goes here
        return numOfSubarrayAtmostK(nums, k) - numOfSubarrayAtmostK(nums, k-1);
        
    }
};