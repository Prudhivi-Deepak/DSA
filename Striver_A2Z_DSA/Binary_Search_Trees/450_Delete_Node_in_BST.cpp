#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            // if root is null return it;
            if(root == nullptr) return nullptr;
    
            //if our key value is less than curr node value then go to left side of tree else right side
            if(key < root->val){
                root->left = deleteNode(root->left, key); 
                // return root;
            }
            else if(key > root->val){
                root->right = deleteNode(root->right, key); 
                // return root;
            }
            else{
    
                // if key equals the root node
    
                // if left of root (keynode) is empty no need any successor just replace 
                // root with its right element
                // that means already this roots parent calls this function we have to return curr root right
    
                if(root->left == nullptr){
                    TreeNode *temp = root->right; delete root; return temp;
                    // return root->right;
                }
                // same for right also
                if(root->right == nullptr){
                    TreeNode *temp = root->left; delete root; return temp;
                    // return root->left;
                }
    
                // find the right successsor - 2 child
    
                TreeNode *rightSuccessor = root->right, *rightSuccessorParent = root;
    
                while(rightSuccessor->left!=nullptr){
                    rightSuccessorParent = rightSuccessor;
                    rightSuccessor = rightSuccessor->left;
                }
    
                root->val = rightSuccessor->val;
    
                //only 2 possiblities for right successor --> 0 child or 1 right child;
    
                // if(rightSuccessorParent){
                    if(rightSuccessorParent->left == rightSuccessor){
                        rightSuccessorParent->left = rightSuccessor->right;
                    }
                    else{
                        rightSuccessorParent->right = rightSuccessor->right;
                    }
                // }
                delete rightSuccessor;
            }
            // cout << root->val << endl;
            // InOrderTraversal(root);
            return root;
        }
    };