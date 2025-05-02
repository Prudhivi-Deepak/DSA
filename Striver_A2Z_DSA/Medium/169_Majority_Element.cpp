
// https://leetcode.com/problems/majority-element/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], cnt=1;
        for(int i=1; i<nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
                // continue;
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele){
                cnt++;
            }
        }

        if(cnt>floor(nums.size()/2)){
            return ele;
        }
        return -1;
    }
};