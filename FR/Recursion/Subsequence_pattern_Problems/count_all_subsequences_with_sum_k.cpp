class Solution{
    public:    	
    int f(int i, vector<int>& nums, int k){
        if(k==0) return 1;
        if(k<0 || i<0) return 0;

        return f(i-1, nums, k-nums[i]) + f(i-1, nums, k);
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here

        // instead of return true or false return 1 or 0
        // then sum all cases
        return f(nums.size()-1, nums, k);
    }
};