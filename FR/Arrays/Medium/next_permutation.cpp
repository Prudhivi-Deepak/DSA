class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Your code goes here

        //  . . . . . . . .
        //  we need to find the incresing sequence from right to left
        //  1 2 0 4 3 8 1
        //            . .
        //  find index at 3 then we need to find just greater elment than 3 and swap it here
        //  and from next index to end sort and keep it
        //  1 2 0 4 8 1 3
        int n = nums.size(), i = n-1;
        while(i>0 && nums[i-1] >= nums[i]){
            i--;
        }

        if(i == 0){
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        int ngeI = n-1;

        while(ngeI >= i){
            if(nums[ngeI] > nums[i-1]){
                swap(nums[i-1], nums[ngeI]);
                break;
            }
            ngeI--;
        }

        sort(nums.begin()+i, nums.end());
    }
};