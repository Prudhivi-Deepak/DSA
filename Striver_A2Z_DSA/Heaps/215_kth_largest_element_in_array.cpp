#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int i=0;
        while(i<nums.size()){
            if(min_heap.size() == k){
                if(min_heap.top() < nums[i]){
                    min_heap.pop();
                    min_heap.push(nums[i]);
                }
            }
            else if(min_heap.size() <k){
                min_heap.push(nums[i]);
            }
            i++;
        }
        return min_heap.top();
    }
};