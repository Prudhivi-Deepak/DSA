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
            f(i, sum, temp_store, result, candidates, target);
    
            sum-=candidates[i];
            temp_store.pop_back();
            f(i+1, sum, temp_store, result, candidates, target);
    
            return;
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result; vector<int> temp_store;
            f(0, 0, temp_store, result, candidates, target);
            return result;
        }
    };