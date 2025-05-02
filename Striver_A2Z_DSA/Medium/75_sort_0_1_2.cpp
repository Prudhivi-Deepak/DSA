// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L=0, M=0, R=nums.size()-1;
        while(M<=R && R>0){
            // while(nums[R]==2 && R>0){R--;}
            // while(nums[L]==0 && L<nums.size()-1){L++;}

            if(nums[M]==2){
                swap(nums[M], nums[R--]);
            }
            else if(nums[M]==0){
                swap(nums[M++], nums[L++]);
            }
            else if(nums[M]==1){
                M++;
            }
        }
    }
};