
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

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> topView;
        map<int,int> top_values ;// column, value;

        queue<pair<TreeNode*, int>> q; // node, column
        q.push({root, 0});
        while(!q.empty()){
            auto [currNode, column] = q.front();q.pop();
            if(top_values.find(column)==top_values.end()){
                top_values.insert({column, currNode->val});
            }
            if(currNode->left) q.push({currNode->left, column-1});
            if(currNode->right) q.push({currNode->right, column+1});            
        }

        for(auto m : top_values){
            topView.push_back(m.second);
        }

        return topView;
    }
};