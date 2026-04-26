class Solution {
public:
    void f(int i, vector<int>& candidates, int target, vector<int> subset, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(subset);
            return;
        }

        if(target < 0 || i<0) return ;

        // not take
        f(i-1, candidates, target, subset, ans);

        // take
        subset.push_back(candidates[i]);
        f(i, candidates, target-candidates[i], subset, ans);
        subset.pop_back();        

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> subset;
        f(candidates.size()-1, candidates, target, subset, ans);
        return ans;
    }
};