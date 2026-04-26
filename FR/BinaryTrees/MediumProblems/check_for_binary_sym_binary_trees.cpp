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
    bool isEqual(TreeNode *root1, TreeNode *root2){
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;

        return (root1->data == root2->data) && isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left);
    }


    bool isSymmetric(TreeNode* root) {
        //your code goes here
        if(root == nullptr) return true;
        return isEqual(root->left, root->right);
    }
};