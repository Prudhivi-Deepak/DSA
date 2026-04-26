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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //your code goes here

        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;

        return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};