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
    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapifyDown(nums, i);
        }
    }
};