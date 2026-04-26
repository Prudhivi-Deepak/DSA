class Solution {
public:
    void heapifyDown(vector<int> &nums, int index, int limit){
        // cout << "heapify : "<< index << " : " << limit << endl;

        // for(int i=0; i<nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        
        while(index < limit){

            int child1 = 2*index+1, child2 = 2*index+2;

            int largest_index = index;

            if(child1 < limit && nums[child1] > nums[largest_index]) largest_index = child1;
            if(child2 < limit && nums[child2] > nums[largest_index]) largest_index = child2;

            if(largest_index == index) break;
            swap(nums[largest_index], nums[index]);
            index = largest_index;
        }

        // for(int i=0; i<nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
    }

    void heapSort(vector<int>&nums) {
        int n = nums.size();
        for(int i=(n/2); i>=0; i--){
            heapifyDown(nums, i, n);
        }

        for(int i=n-1; i>0; i--){
            swap(nums[0], nums[i]);
            heapifyDown(nums, 0, i);
        }        
    }
};