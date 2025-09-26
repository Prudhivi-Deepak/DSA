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
        int kthsmall, kthlarge, counter = 0, counter2=0;
        void KthSmallest(TreeNode *root, int k){
            if(root==nullptr) return;
            KthSmallest(root->left, k);
            counter++;
            // cout << root->val << " : "<< counter << " "<<endl;
            if(counter==k){
                kthsmall = root->val;return;
            }
            KthSmallest(root->right, k);
        }
    
        void KthLargest(TreeNode *root, int k){
    
            if(root==nullptr) return;
            KthLargest(root->right, k);
            counter2++;
            if(counter2 == k){
                kthlarge = root->val;return;
            }
            KthLargest(root->left, k);
        }
        int kthSmallest(TreeNode* root, int k) {
            KthSmallest(root, k);
            // KthLargest(root, k);
            return kthsmall;
        }
    };