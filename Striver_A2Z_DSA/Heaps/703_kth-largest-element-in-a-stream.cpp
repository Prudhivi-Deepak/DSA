#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int k1;
        KthLargest(int k, vector<int>& nums) {
            k1= k;
            for(int i=0; i<nums.size(); i++){
                if(min_heap.size()==k){
                    if(nums[i] > min_heap.top()){
                        min_heap.pop();
                        min_heap.push(nums[i]);
                    }
                }
                else{
                    min_heap.push(nums[i]);
                }
            }
        }
        
        int add(int val) {
    
            if(min_heap.empty() || min_heap.size() <= k1-1){
                min_heap.push(val);
            }
            else if(val > min_heap.top()){
                min_heap.pop();
                min_heap.push(val);
            }
            return min_heap.top();
        }
    };
    
    /**
     * Your KthLargest object will be instantiated and called as such:
     * KthLargest* obj = new KthLargest(k, nums);
     * int param_1 = obj->add(val);
     */