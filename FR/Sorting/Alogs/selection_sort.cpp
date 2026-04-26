class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        // selection sort --> sorted and unsorted array
        // select min of unsorted array and put at the end of sorted array

        // first index goes from 0 to n-2 
        //  -> for index=0 get min from (1, n-1)
        //  -> for index=1 get min from (2, n-1)
        //  -> for index=2 get min from (3, n-1) 

        for(int index=0; index<nums.size(); index++){
            int min_index = index;
            for(int j=index+1; j<nums.size(); j++){
                if(nums[j] < nums[min_index]){
                    min_index = j;
                }
            }
            swap(nums[min_index], nums[index]);
        }
        return nums;
    }
};
