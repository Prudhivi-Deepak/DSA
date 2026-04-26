class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        //your code goes here

        int ones = 0, twos = 0;

        for(int i=0; i<nums.size(); i++){
            ones = (ones^nums[i])&~twos;
            twos = (twos^nums[i])&~ones;
        }
        return ones;
    }
};