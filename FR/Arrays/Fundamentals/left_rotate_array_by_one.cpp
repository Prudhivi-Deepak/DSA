class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {

        // store nums[0] in temp variable and shift 1 to n-1 to i-1 position
        // then assign temp to nums[n-1]

        int temp = nums[0];

        for(int i=1; i<nums.size(); i++){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = temp;
    }
};