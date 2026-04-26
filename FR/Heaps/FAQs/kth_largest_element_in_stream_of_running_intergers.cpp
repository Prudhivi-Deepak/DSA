class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> minHeap;
int K;
  KthLargest(int k, vector<int>& nums) {
    // minheap
    K = k;
    for(int i=0; i<nums.size(); i++){
        if(minHeap.size() < k){
            minHeap.push(nums[i]);
        }
        else if(minHeap.top() < nums[i]){
            minHeap.push(nums[i]);
            minHeap.pop();
        }
    }
  }

  int add(int val) {
    if(minHeap.size() < K){
        minHeap.push(val);
    }
    else if(minHeap.top() < val){
        minHeap.push(val);
        minHeap.pop();
    }
    return minHeap.top();
  }
};