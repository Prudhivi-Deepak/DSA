class Solution {
public:
    int countSumatmostGoal(vector<int>& nums, int goal){
        int l = 0, r = 0, currSum = 0, n = nums.size(), total_subarrays = 0;

        while( r < n ){
            currSum += nums[r]%2;

            while(currSum > goal){
                currSum -= nums[l]%2; l++;
            }

            if(r>=l) {
                total_subarrays += (r-l+1);
            }
            r++;
        }
        return total_subarrays;
    }

    int numberOfOddSubarrays(vector<int>& nums, int k) {
        //your code goes here
        return countSumatmostGoal(nums, k) - countSumatmostGoal(nums, k-1);
    }
};