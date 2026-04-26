class Solution {
public:

    void heapifyDown(vector<int> &nums, int index){

        while(index < nums.size()){

            int child1 = 2*index+1, child2 = 2*index+2;

            int largest_index = index;

            if(child1 < nums.size() && nums[child1] > nums[largest_index]) largest_index = child1;
            if(child2 < nums.size() && nums[child2] > nums[largest_index]) largest_index = child2;

            if(largest_index == index) break;
            swap(nums[largest_index], nums[index]);
            index = largest_index;
        }

    }

    vector<int> minToMaxHeap(vector<int> nums) {
        for(int i=nums.size()-1; i>=0; i--) heapifyDown(nums, i);
        return nums;
    }
};