
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int cnt1 = 0, cnt2 = 0, ele1 = 0, ele2 = 0, n = nums.size();
            vector<int> result;
    
            for(int i=0; i<nums.size();i++){
                if(ele1 == nums[i]){
                    cnt1++;
                }
                else if(ele2 == nums[i]){
                    cnt2++;
                }
                else if(cnt1 == 0){
                    ele1 = nums[i];cnt1++;
                }
                else if(cnt2==0){
                    ele2 = nums[i];cnt2++;
                }
                else{
                    cnt1--; cnt2--;
                }
            }
    
            cnt1 = 0, cnt2 = 0;
            for(int i=0; i<n; i++){
                if(nums[i] == ele1) cnt1++;
                if(nums[i] == ele2) cnt2++;
                if(cnt1>n/3 && cnt2>n/3) break;
            }
    
            if(cnt1>n/3) result.push_back(ele1);
            if(cnt2>n/3 && (result.empty() || (result.size()>0 && result.back()!=ele2))) {
                result.push_back(ele2);
            }
    
            return result;
        }
    };