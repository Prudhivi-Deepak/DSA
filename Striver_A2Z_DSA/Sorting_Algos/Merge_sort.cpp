#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void MergeArray(int left1, int right1, int left2, int right2, vector<int> &nums){
            int i=left1, j=left2;
            vector<int> ans;
    
            while(i<=right1 && j<=right2){
                if(nums[i] <= nums[j])
                    ans.push_back(nums[i++]);
                else
                    ans.push_back(nums[j++]);
            }
    
            while(i<=right1) ans.push_back(nums[i++]);
            while(j<=right2) ans.push_back(nums[j++]);
    
            i = left1;
            int index = 0;
    
            while(i<=right2){
                nums[i++] = ans[index++];
            }
    
        }
    
        void DivideArray(int left, int right, vector<int> &nums){
    
            if(left >= right) return;
    
            int mid = (left+right)/2;
    
            DivideArray(left, mid, nums);
            DivideArray(mid+1, right, nums);
            MergeArray(left, mid, mid+1, right, nums);
        }
    
        vector<int> mergeSort(vector<int>& nums) {
            DivideArray(0, nums.size()-1, nums);
            return nums;
        }
    };
    