class Solution {
public:
    
    void heapifyUp(vector<int> &nums, int ind){

        while(ind>0){
            // if current child and parent not in good condition
            // means for min heap parent should be min and child should be maximum
            // if child < parent -- swap
            int parent = (ind-1)/2;
            if(parent>=0 && nums[ind] < nums[parent]){
                swap(nums[ind], nums[parent]);
                ind = parent;
            }
            else break;
        }
    }

    void heapifyDown(vector<int> &nums, int ind){

        while(ind<nums.size()){
            int child1 = 2*ind+1, child2 = 2*ind+2;

            // get smallest of child1 child2 and parent
            // if parent is not the one, replace the parent with the smallest one
            // then go down to the child with replaced 
            int smallest_index = ind;

            if(child1 < nums.size() && nums[child1] < nums[smallest_index]) smallest_index = child1;
            if(child2 < nums.size() && nums[child2] < nums[smallest_index]) smallest_index = child2;
            if(smallest_index == ind) break;
            swap(nums[smallest_index], nums[ind]);
            
            ind = smallest_index;
        }
    }

    void heapify(vector<int> &nums, int ind, int val) {
        nums[ind] = val;

        int parent = (ind-1)/2;

        // if ind and it's parent violates heapify heapifyUp else heapifyDown
        if(parent >=0 && nums[ind] < nums[parent]){
            heapifyUp(nums, ind);
        }
        else{
            heapifyDown(nums, ind);
        }
    }
};