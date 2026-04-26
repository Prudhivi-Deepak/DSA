/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root==nullptr || root==p || root==q) return root;

        TreeNode *L = LCA(root->left,p,q);
        TreeNode *R = LCA(root->right,p,q);
        if(L && R) return root;
        if(L) return L;
        if(R) return R;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //your code goes here

        // find common Ancestor which is near to both p and q

        // find p and q traversing dfs or inorder

        // if found p or q return it and 
        return LCA(root, p, q);
    }
};