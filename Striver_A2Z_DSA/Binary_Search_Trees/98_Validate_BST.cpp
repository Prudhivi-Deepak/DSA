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
        bool check(TreeNode *root, long l, long h){
            if(root==nullptr) return true;
            return (l<root->val) && (root->val < h) && check(root->left, l, root->val) && check(root->right, root->val, h);
        }
        bool isValidBST(TreeNode* root) {
            return check(root, (long) INT_MIN-1, (long)INT_MAX+1);
        }
    };