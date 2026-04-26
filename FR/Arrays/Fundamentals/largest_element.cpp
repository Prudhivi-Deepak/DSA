class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxEle = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(maxEle < nums[i]) {maxEle = nums[i];}
        }
        return maxEle;
    }
};