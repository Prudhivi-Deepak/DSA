class Solution {
public:
    void f(int i, vector<int>& candidates, int target, vector<int> subset, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(subset);
            return;
        }

        if(target < 0 || i<0) return ;
        // take

        subset.push_back(candidates[i]);
        f(i-1, candidates, target-candidates[i], subset, ans);
        subset.pop_back();
        
        
        // not take
        while(i>0 && candidates[i] == candidates[i-1]){
            i--;
        }
        f(i-1, candidates, target, subset, ans);
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        f(candidates.size()-1, candidates, target, subset, ans);
        return ans;
    }
};