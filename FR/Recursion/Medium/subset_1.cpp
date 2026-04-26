class Solution {
  public:
    
    void f(int i, vector<int>& nums, int sum, vector<int> &ans){

        if(i<0){
            ans.push_back(sum); return;
        }

        // not take
        f(i-1, nums, sum, ans);

        // take
        f(i-1, nums, sum+nums[i], ans);
    }

    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int> ans;
        f(nums.size()-1, nums, 0 , ans);
        return ans;
    }
};