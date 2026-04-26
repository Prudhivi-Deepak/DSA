class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        // 0 1 2 3 4
        // 7 4 1 5 3
        // ...5 times
        // shift the insert in correct position

        for(int i=1; i<nums.size(); i++){
            int index = i-1, insert_val = nums[i];
            while(index>=0){
                if(nums[index] > insert_val){
                    nums[index+1] = nums[index];
                    index--;
                }
                else break;
            }
            nums[index+1] = insert_val;
        }
        return nums;
    }
};
