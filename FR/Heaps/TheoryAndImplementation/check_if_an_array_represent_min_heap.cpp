class Solution {
public:
    bool isValid(int index, vector<int>& nums){

        if(index >= nums.size()) return true;
        int child1 = 2*index+1, child2 = 2*index+2;

        bool left  = (child1 < nums.size()) ? (nums[child1] >= nums[index]) : true;
        bool right  = (child2 < nums.size()) ? (nums[child2] >= nums[index]) : true;
        
        return left && right && isValid(child1, nums) && isValid(child2, nums);
    }

    bool isHeap(vector<int>& nums) {
        return isValid(0, nums);        
    }
};