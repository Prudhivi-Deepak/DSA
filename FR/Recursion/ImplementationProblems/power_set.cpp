class Solution {
public:	
    void f(int i, vector<int>& nums, vector<int> subset, vector<vector<int>> &powerSet){

        if(i>nums.size()) return;

        if(i==nums.size()){
            powerSet.push_back(subset);
            return;
        }

        // not take
        f(i+1, nums, subset, powerSet);

        // take
        subset.push_back(nums[i]);
        f(i+1, nums, subset, powerSet);
        subset.pop_back();
    }

    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<int> subset;
        vector<vector<int>> powerSet;

        f(0, nums, subset, powerSet);
        return powerSet;
        // i can easily use mask and compute using for loops
        // but this is recursion so take or not take work i get


    }
};