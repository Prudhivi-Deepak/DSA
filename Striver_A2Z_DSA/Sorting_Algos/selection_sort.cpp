
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> selectionSort(vector<int>& nums) {
            for(int i=0; i<nums.size()-1; i++){
                int min_Index = i;
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[min_Index]> nums[j]){
                        min_Index = j;
                    }
                }
                swap(nums[i], nums[min_Index]);
            }
            return nums;
        }
    };
    