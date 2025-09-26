#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> insertionSort(vector<int>& nums) {
            int n = nums.size();
            for(int i=1; i<n; i++){
                int curr_ele = nums[i], j=i-1;
                while(j>=0){
                    if(curr_ele < nums[j]){
                        nums[j+1] = nums[j];
                        j--;
                    }
                    else{
                        break;
                    }
                }
                nums[j+1] = curr_ele;
            }
            return nums;
        }
    };
    