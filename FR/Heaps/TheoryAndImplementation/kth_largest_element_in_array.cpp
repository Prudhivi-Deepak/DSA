class Solution {
public:

    // 6 7 8 9 1 2 3 4 5  k = 4
    // minHeap = {6 7 8 9}

    
    int kthLargestElement(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i=0;

        while(i<nums.size()){
            if(minHeap.empty() || minHeap.size() < k) minHeap.push(nums[i]);
            else if(minHeap.top() < nums[i] ){
                minHeap.push(nums[i]);
                minHeap.pop();
            }
            i++;
        }
        return minHeap.top();
    }
};