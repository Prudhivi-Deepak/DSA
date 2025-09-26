
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
        void inorder_helper(TreeNode* root, vector<int> &inorder_traversal){
            if(!root) return;
            inorder_helper(root->left, inorder_traversal);
            inorder_traversal.push_back(root->val);
            inorder_helper(root->right, inorder_traversal);
        }
        TreeNode * FindRightMostNode(TreeNode *StartNode , TreeNode *root, vector<int> &Morris_inorder){
            
            while(root->right){
                if(root->right == StartNode){
                    Morris_inorder.push_back(StartNode->val);
                    root->right  = nullptr;
                    return StartNode->right;
                }
                root = root->right;
            }
    
            root->right = StartNode;
            return StartNode->left;
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> Morris_inorder;
            while(root!=nullptr){
    
                if(root->left==nullptr) {
                    Morris_inorder.push_back(root->val);
                    root = root->right;
                }
                else{
                    root = FindRightMostNode(root, root->left, Morris_inorder);
                }
            }
            return Morris_inorder;
            // vector<int> inorder_traversal;
            // inorder_helper(root, inorder_traversal);
            // return inorder_traversal;
        }
    };