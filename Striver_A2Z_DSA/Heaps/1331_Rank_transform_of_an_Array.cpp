
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans(n);
    
            if(n==0) return ans;
    
            auto compare = [](pair<int,int> p1, pair<int,int> p2){
                return p1.first > p2.first;
            };
    
            // vector<pair<int,int>> pair_arr;
    
            priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> min_heap(compare);
    
            for(int i=0; i<n; i++){
                // pair_arr.push_back({arr[i], i});
                min_heap.push({arr[i],i});
            }
    
            int rank = 1;
            pair<int,int> prev = min_heap.top(), curr;
            ans[prev.second] = rank;
            min_heap.pop();
    
            while(!min_heap.empty()){
                curr = min_heap.top(); min_heap.pop();
                if(curr.first != prev.first){
                    ans[curr.second] = ++rank;
                }
                else{
                    ans[curr.second] = rank;
                }
                prev = curr;
            }
    
            // vector<int> dummyarray = arr;
            // sort(dummyarray.begin(), dummyarray.end());
            // unordered_map<int,int> umap;
            // int rank = 1;
            // for(int i=0; i<n; i++){
            //     if(umap[dummyarray[i]]==0 ){
            //         umap[dummyarray[i]] = rank++;
            //     }
            // }
    
            // vector<int> ans;
            // for(int i=0; i<n; i++){
            //     ans.push_back(umap[arr[i]]);
            // }
    
            return ans;
        }
    };