class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // iterate and shift all non zeroes to beginning using swap with zero index in the beggining
        // 0 1 4 0 5 2
        // 1 4 5 2 0 0
        //           i
        //         j

        int index = 0, i =0; 

        while(i<nums.size()){
            if(nums[i]!=0){
                if(index==i){index++; i++;}
                else swap(nums[index++], nums[i]);
            }
            else{
                i++;
            }
        }
        
    }
};