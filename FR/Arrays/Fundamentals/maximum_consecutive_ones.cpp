class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        // 1 1 0 0 1 1 1 0
        // count the ones untill you see 0 then, count them again from 0

        int count = 0, maxLen = 0;

        for(auto i : nums){
            if(i==0){
                maxLen = max(maxLen, count);
                count=0;
            }
            else count++;
        }
        maxLen = max(maxLen, count);
        return maxLen;                
    }
};