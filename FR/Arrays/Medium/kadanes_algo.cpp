class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // kadane's algorithm is simple
        // keep track of maxSum and currSum
        // we set currSum to 0 if it goes < 0 because we don't have to consider that window because it reduces the future maxSum

        int maxSum = INT_MIN, currSum = 0;

        for(int i: nums){
            currSum += i;
            maxSum = max(maxSum, currSum);
            if(currSum<0) currSum = 0;
        }
        return maxSum;        
    }
};