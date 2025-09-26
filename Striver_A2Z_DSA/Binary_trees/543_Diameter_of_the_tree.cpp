
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
        int findHeight(TreeNode *root, int &diameter){
            if(root==NULL) return 0;
    
            int leftHeight = findHeight(root->left, diameter);
            int rightHeight = findHeight(root->right, diameter);
            diameter = max(diameter, leftHeight+rightHeight);
    
            return max(leftHeight,rightHeight)+1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int diameter = 0;
            findHeight(root, diameter);
            return diameter;
        }
    };