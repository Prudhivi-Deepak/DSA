#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
            deque<int> dq;
            int i=0;
            vector<int> ans;
    
            while(i<nums.size()){
    
                while(!dq.empty() && nums[dq.back()] < nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
                
                if(i+1 >=k){
                    while(!dq.empty() && dq.back() - dq.front() +1 > k){
                        dq.pop_front();
                    }
                    if(!dq.empty()) ans.push_back(nums[dq.front()]);
                }
                i++;
            }
    
            return ans;
    
    
            // if (k==1) return nums;
            // int maxi = nums[0];
            // vector<int> ans;
            // for(int i=0; i<k; i++){
            //     maxi = max(maxi, nums[i]);
            // }
            // ans.push_back(maxi);
            // for(int i=k; i<nums.size(); i++){
            //     maxi = max(maxi, nums[i]);
            //     ans.push_back(maxi);+
    
            // }
            // return ans;
        }
    };