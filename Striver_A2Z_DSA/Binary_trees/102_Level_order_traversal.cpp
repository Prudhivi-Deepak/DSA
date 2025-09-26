
// Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};
 

 class Solution {
    public:
        void levelorder_helper(TreeNode *root, int level, vector<vector<int>> &levelorder_traversal){
            
            if(!root) return;
    
            if(level == levelorder_traversal.size()) levelorder_traversal.push_back({});
            
            levelorder_helper(root->left, level+1, levelorder_traversal);
            levelorder_traversal[level].push_back(root->data);
            levelorder_helper(root->right, level+1, levelorder_traversal);
    
        }
        vector<vector<int> > levelOrder(TreeNode* root) {
            //your code goes here
            vector<vector<int>> levelorder_traversal;
            levelorder_helper(root, 0, levelorder_traversal);
            return levelorder_traversal;
        }
    };