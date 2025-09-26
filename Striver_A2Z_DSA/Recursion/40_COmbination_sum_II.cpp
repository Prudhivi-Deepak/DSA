#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
        void f(int i, int sum, vector<int> &temp_store, vector<vector<int>> &result, vector<int>& candidates, int &target){
            if(sum == target){
                result.push_back(temp_store);
                return;
            }
            if(sum > target || i >= candidates.size()) return;
    
            sum += candidates[i];
            temp_store.push_back(candidates[i]);
            f(i+1, sum, temp_store, result, candidates, target);
    
            // not take - but next duplicates might be taken right so eliminating the duplicate options for not take;
            int ind = i;
            while(ind+1 < candidates.size() && candidates[ind] == candidates[ind+1]){
                ind++;
            }
            // cout << ind << " : " << candidates[ind] << " | ";
            sum-=candidates[ind];
            temp_store.pop_back();
            f(ind+1, sum, temp_store, result, candidates, target);
    
            return;
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> result; vector<int> temp_store;
            f(0, 0, temp_store, result, candidates, target);
            return result;
        }
    };