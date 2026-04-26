class Solution {
public:
    int countSumatmostGoal(vector<int>& nums, int goal){
        int l = 0, r = 0, currSum = 0, n = nums.size(), total_subarrays = 0;

        while( r < n ){
            currSum += nums[r];

            while(currSum > goal){
                currSum -= nums[l]; l++;
            }

            if(r>=l) {
                total_subarrays += (r-l+1);
            }
            r++;
        }
        return total_subarrays;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //your code goes here
        return countSumatmostGoal(nums, goal) - countSumatmostGoal(nums, goal-1);
    }
};