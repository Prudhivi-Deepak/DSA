
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


class Solution {
    public:
        int InorderTraversalWithCount(TreeNode* root, int count){
            if(root==nullptr) return count;
            int count1 = InorderTraversalWithCount(root->left, count+1);
            int count2 = InorderTraversalWithCount(root->right, count+1);
            return max(count1, count2);
        }
        int maxDepth(TreeNode* root) {
            // return InorderTraversalWithCount(root, 0);
            if(root==nullptr) return 0;
            queue<pair<TreeNode*,int>> q;
            q.push({root, 1});
            int max_level = 0;
            while(!q.empty()){
                auto [node, level] = q.front(); q.pop();
                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
    
                if(q.empty()) max_level = level;
            }
            return max_level;
        }
    };