#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void f(int i, int sum, int k, int n, vector<int> &temp_store, vector<vector<int>> &result){
    
            if(temp_store.size() > k || i>10) return;
    
            if(temp_store.size() == k && sum == n){
                result.push_back(temp_store);
                return;
            }
    
            temp_store.push_back(i);
            f(i+1, sum+i, k, n, temp_store, result);
    
            temp_store.pop_back();
            f(i+1, sum, k, n, temp_store, result);
    
            return;
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> result;
            vector<int> temp_store;
    
            f(1, 0, k, n, temp_store, result);
    
            return result;
        }
    };