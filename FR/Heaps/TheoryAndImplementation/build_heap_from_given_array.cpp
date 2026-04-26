class Solution {
public:

    void heapifyDown(vector<int> &nums, int ind){

        while(ind < nums.size()){

            int child1 = 2*ind+1, child2 = 2*ind+2;

            int smallest_index = ind;

            if(child1 < nums.size() && nums[child1] < nums[smallest_index]) smallest_index = child1;
            if(child2 < nums.size() && nums[child2] < nums[smallest_index]) smallest_index = child2;

            if(smallest_index == ind) break;
            swap(nums[smallest_index], nums[ind]);
            ind = smallest_index;
        }

    }

    void buildMinHeap(vector<int> &nums) {
        for(int i=nums.size()-1; i>=0; i--)
            heapifyDown(nums, i);
    }
};