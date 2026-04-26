class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {

        // maintain 3 pointers and 
        // zero, one, two 
        // zero & one starts at 0 index 
        // two at n-1 index
        // one passes 1's and if it encounter zero it swaps with zero++ and
        // check the current element again
        // if it is 2 then swap with two--

        // 0 0 1 1 1
        // l
        // m       
        //         r

        int l=0, mid = 0, r = nums.size()-1;

        while(mid<=r){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==0){
                if(l==mid){
                    l++; mid++;
                }
                else{
                    swap(nums[mid], nums[l++]);
                }
            }
            else{
                swap(nums[mid], nums[r--]);
            }         
        }        
    }
};