#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void MaxHeapifyUp(vector<int> &nums){
        int n = nums.size();
        for(int i=ceil(n/2); i<n; i++){
            int ind = i;
            while(i>0){
                int parent_i = (i%2) ? (i-1)/2 : (i-2)/2;

                if(nums[parent_i] < nums[i]){
                    swap(nums[i], nums[parent_i]);
                    i = parent_i;
                }
                else break;
            }
        }
    }

    void MaxheapifyDown(vector<int> &nums){
        int n = nums.size();
        for(int ind = ceil(n/2)-1; ind>=0; ind--){
            int i = ind;
            while(i<n){
                int largest = i, left = 2*i+1, right = 2*i+2;
                if(left < n && nums[left]  > nums[largest]) largest = left;
                if(right < n && nums[right]  > nums[largest]) largest = right;

                if(largest != i){
                    swap(nums[i], nums[largest]);
                    i = largest;
                }
                else break;
                // cout << nums[i] << " " ;
            }
        }
        // cout << endl;
    }
    vector<int> minToMaxHeap(vector<int> nums) {
        MaxheapifyDown(nums);
        // MaxHeapifyUp(nums);
        // for(auto p: nums){
        //     cout << p << " ";
        // }
        // cout << endl;
        // for(auto p: nums){
        //     cout << p << " ";
        // }
        return nums;
    }
};