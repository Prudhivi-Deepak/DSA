class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // we know array has 0 to n and sum of first 1 to n natural numbers is n*(n+1)/2
        // so we find expSum = n*(n+1)/2 then arr sum
        // return expSum - arr sum

        int n = nums.size(), expSum = n*(n+1)/2, sum = 0;

        for(int i: nums){
            sum+=i;
        }
        
        return expSum - sum;
    }
};