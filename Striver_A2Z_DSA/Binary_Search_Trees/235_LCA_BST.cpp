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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // int currNode = root->val;
            // if(currNode < p->val && currNode < q->val){
            //     // then i will find them in right subtree;
            //     return lowestCommonAncestor(root->right, p, q);
            // }
            // if(currNode > p->val && currNode > q->val){
            //     return lowestCommonAncestor(root->left, p, q);
            // }
            // return root;
    
            while(root){
                int currNode = root->val;
                if(currNode < p->val && currNode < q->val){
                    root = root->right;
                }
                else if(currNode > p->val && currNode > q->val){
                    root = root->left;
                }
                else{
                    return root;
                }
            }
            return root;
        }
    };