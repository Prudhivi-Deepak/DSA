class Solution {
public:
    void f(int i, vector<int>& nums, vector<int> subset, vector<vector<int>> &ans){
        if(i == -1){
            ans.push_back(subset);
            return;
        }
        // take
        subset.push_back(nums[i]);
        f(i-1, nums, subset, ans);
        subset.pop_back();
        
        // not take
        while(i>0 && nums[i] == nums[i-1]){
            i--;
        }
        f(i-1, nums, subset, ans);
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        f(nums.size()-1, nums, subset, ans);
        return ans;
    }
};