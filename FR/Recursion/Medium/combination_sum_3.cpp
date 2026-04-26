class Solution {
public:
    void f(int i, int sum, int k, vector<int> subset, vector<vector<int>> &ans){

        if(subset.size()==k && sum == 0){
            ans.push_back(subset); return;
        }

        if(sum < 0 || i<=0 || subset.size()>k) return;

        // not take
        f(i-1, sum, k, subset, ans);

        // take
        subset.push_back(i);
        f(i-1, sum-i, k, subset, ans);
        subset.pop_back();
    }

    vector<vector<int> > combinationSum3(int k, int n) {
    	//your code goes here

        vector<int> subset;
        vector<vector<int>> ans;

        f(9, n, k, subset, ans);

        return ans;

        // lets say i have 1 to 9 numbers in the array
        // i can take k numbers to form sum n 
        // instead of array i can use index itself as number right


    }
};