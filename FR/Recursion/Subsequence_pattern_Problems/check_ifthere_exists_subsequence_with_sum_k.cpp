class Solution{
    public:
    
    bool f(int i, vector<int>& nums, int k){
        if(k==0) return true;
        if(k<0 || i<0) return false;

        return f(i-1, nums, k-nums[i]) || f(i-1, nums, k);
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here

        //  take or not take
        return f(nums.size()-1, nums, k);
    }
};