
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
        TreeNode *first = nullptr,* middle = nullptr, *last = nullptr, *prev = nullptr;
        void inorder(TreeNode *root){
            if(root==nullptr) return ;
            inorder(root->left);
    
            if(prev && prev->val > root->val){
                if(first == nullptr){
                    first = prev;
                    middle = root;
                }
                else{
                    last = root;return;
                }
            }
            prev = root;
            inorder(root->right);
        }
        void recoverTree(TreeNode* root) {
            inorder(root);
    
           if(first !=nullptr && last!=nullptr){
                int temp = first->val;
                first->val = last->val;
                last->val = temp;
           }
           else{
                int temp = first->val;
                first->val = middle->val;
                middle->val = temp;
           }
        }
    };