#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int quickSortUsingPivot(int left, int right, vector<int> &nums){
            int i = left, index = left, pivot = right;
    
            while(i<pivot){
                if(nums[i]<=nums[pivot]){
                    swap(nums[index], nums[i]);
                    if(index==i){
                        index++;i++;
                    }
                    else index++;
                }
                else
                    i++;
            }
    
            swap(nums[index], nums[pivot]);
    
            return index;//returning pivot so next sorting happens before and after this index;
        }
    
        void CallQuickSortRecursively(int left, int right, vector<int> &nums){
            int pivot = quickSortUsingPivot(left, right, nums);
    
            if(left<pivot-1) CallQuickSortRecursively(left, pivot-1, nums);
            if(pivot+1<right) CallQuickSortRecursively(pivot+1, right, nums);
        }
    
        vector<int> quickSort(vector<int>& nums) {
            CallQuickSortRecursively(0, nums.size()-1, nums);
            return nums;
        }
    };
    