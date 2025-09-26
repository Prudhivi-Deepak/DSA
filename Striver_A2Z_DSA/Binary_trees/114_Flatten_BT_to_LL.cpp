
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
        TreeNode * markNextNode(TreeNode * root, TreeNode *StartNode){
            while(root->right){
                root = root->right;
            }
            root->right = StartNode->right;
            StartNode->right = StartNode->left;
            StartNode->left = nullptr;
            return StartNode->right;
    
        }
        void flatten(TreeNode* root) {
            while(root){
                if(root->left==nullptr){
                    root = root->right;
                }
                else{
                    root = markNextNode(root->left, root);
                }
            }
        }
    };