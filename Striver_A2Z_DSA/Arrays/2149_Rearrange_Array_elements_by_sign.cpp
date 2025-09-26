
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int pos_ind = 0, neg_ind=1, curr_ind = 0;
            vector<int> result(nums.size(), 0);
    
            for(int curr_ind = 0; curr_ind<nums.size(); curr_ind++){
                if(nums[curr_ind] <0){
                    result[neg_ind] = nums[curr_ind];
                    neg_ind+=2; 
                }
                else{
                    result[pos_ind] = nums[curr_ind];
                    pos_ind+=2;
                }
            }
    
            // while(curr_ind < nums.size()){
    
            //     if(nums[curr_ind] <0){
            //         result[neg_ind] = nums[curr_ind];
            //         neg_ind+=2; 
            //     }
            //     else{
            //         result[pos_ind] = nums[curr_ind];
            //         pos_ind+=2;
            //     }
                // curr_ind++;
    
                // while(pos_ind < nums.size() && nums[pos_ind]<0){pos_ind++;}
                // while(neg_ind < nums.size() && nums[neg_ind]>0){neg_ind++;}
    
                // if(curr_ind%2) result[curr_ind] = nums[neg_ind++];
                // else result[curr_ind] = nums[pos_ind++];
                // curr_ind++;
            // }
            return result;
        }
    };