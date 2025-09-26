#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapifyDown(vector<int> &nums, int ind) {
        int n = nums.size();
        while (true) {
            int smallest = ind;
            int left = 2 * ind + 1;
            int right = 2 * ind + 2;

            if (left < n && nums[left] < nums[smallest]) {
                smallest = left;
            }

            if (right < n && nums[right] < nums[smallest]) {
                smallest = right;
            }

            if (smallest != ind) {
                swap(nums[ind], nums[smallest]);
                ind = smallest;
            } else {
                break;
            }
        }
    }
    void heapify(vector<int> &nums, int ind, int val) {
        int n = nums.size();
        nums[ind] = val;

        // chweck parents value
        int i = ind;
        while(i!=0){
            int p_i = (i%2) ? (i-1)/2 : (i-2)/2;

            if(nums[p_i] > nums[i]){
                swap(nums[p_i], nums[i]);
                i = p_i;
            }
            else break;
        }

        heapifyDown(nums, ind);


        // chweck child's value
        // i = ind;
        // while(i<nums.size()-1){
        //     int c1_i = 2*i+1, c2_i = 2*i+2;

        //     if((c1_i<n && nums[c1_i] <= nums[i]) || (c2_i<n && nums[c2_i] <= nums[i])){
        //         if(nums[c1_i] < nums[c2_i]){
        //             swap(nums[c1_i], nums[i]);
        //             i = c1_i;
        //         }
        //         else{
        //             swap(nums[c2_i], nums[i]);
        //             i = c2_i;
        //         }
        //     }
        //     else if(c1_i<n && nums[c1_i] <= nums[i]){
        //         swap(nums[c1_i], nums[i]);
        //         i = c1_i;
        //     }
        //     else if(c2_i<n && nums[c2_i] <= nums[i]){
        //         swap(nums[c2_i], nums[i]);
        //         i = c2_i;
        //     }
        //     else break;
        // }
    }
};