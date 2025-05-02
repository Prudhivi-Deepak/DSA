#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        // for(int i=0; i<nums.size(); i++){
        for(int i:nums){
            num ^= i;
        }
        return num;
    }
};