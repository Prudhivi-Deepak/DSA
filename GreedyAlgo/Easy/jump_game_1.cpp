class Solution {
public:
    bool canJump(vector<int>& nums) {
        //your code goes here
        int maxReach = 0;
        // 0 1 2 3 4
        // 1 2 2 1 0
        // 1 3 4 
        // 3 2 1 0 4

        // 3 3 3 
        

        for(int i=0; i<nums.size(); i++){
            if(maxReach<i) return false;
            maxReach = max(maxReach, i+nums[i]);
            if(maxReach>=nums.size()-1) return true;
        }
        return false;
    }
};