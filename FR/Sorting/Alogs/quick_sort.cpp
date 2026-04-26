class Solution {
public:
    // 0 1 2 3 4
    // 7 4 1 5 3
    // consider pivot = 3 (index 4)
    // 

    int returnPivot(vector<int>& nums, int left, int right){
        int pivot = right, i = left, index = left;

        while(i<pivot){
            if(nums[i]<=nums[pivot]){
                // if element is less than pivot element--> swap the index and i 
                if(index==i) i++;
                else swap(nums[index], nums[i]);
                index++;
            }
            else i++;
        }

        swap(nums[index], nums[pivot]);
        return index;
    }

    void partition(vector<int>& nums, int left, int right){
        
        int pivot = returnPivot(nums, left, right);
        
        if(left < pivot-1) partition(nums, left, pivot-1);
        if(pivot+1 < right) partition(nums, pivot+1, right);
    }

    vector<int> quickSort(vector<int>& nums) {
        // pivot = partition(arr);
        partition(nums, 0, nums.size()-1);

        return nums;
    }
};
