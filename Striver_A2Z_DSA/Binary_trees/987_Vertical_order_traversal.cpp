
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
    }
};
class Solution {
public:
    void verticalTraversal(TreeNode *root, int L, int c, map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>> &min_heap_map){
        if(root == nullptr) return;
        if(min_heap_map.find(c)==min_heap_map.end()){
            // mp[c] = {root->data};
            // mp.insert({c, {root->data}});
            priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> min_heap;
            min_heap.push(pair<int,int>(L,root->val));
            min_heap_map[c] = min_heap;
        }
        else{
            // mp[c].push_back(root->data);
            min_heap_map[c].push(pair<int,int>(L, root->val));
        }
        verticalTraversal(root->left, L+1, c-1, min_heap_map);
        verticalTraversal(root->right, L+1, c+1, min_heap_map);        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>> min_heap_map;
        verticalTraversal(root, 0, 0, min_heap_map);

        vector<vector<int>> verticalTraversalArray;
        vector<int> eachrow ;
        for(auto m = min_heap_map.begin(); m!=min_heap_map.end(); m++){
            eachrow = {};
            while(!min_heap_map[m->first].empty()){
                eachrow.push_back(min_heap_map[m->first].top().second);min_heap_map[m->first].pop();
            }
            // for(int ele : min_heap_map[m->first]){
                // eachrow.push_back(ele.second);
            // }
            verticalTraversalArray.push_back(eachrow);
        }
        return verticalTraversalArray;
    }
};