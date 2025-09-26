
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
        int LeftHeight(TreeNode *root){
            int count = 1;
            while(root){
                root = root->left;
                count++;
            }
            return count;
        }
        int RightHeight(TreeNode *root){
            int count = 1;
            while(root){
                root = root->right;
                count++;
            }
            return count;
        }
        int countNodes(TreeNode* root) { 
            //your code goes here
    
            if(root==nullptr) return 0;
    
            int lh = LeftHeight(root->left);
            int rh = RightHeight(root->right);
    
            if(lh==rh) return (1<<lh)-1;
    
            return 1 + countNodes(root->left) + countNodes(root->right);
            // queue<TreeNode*> q;
            // q.push(root);
            // int count = 0;
    
            // while(!q.empty()){
            //     TreeNode *currNode = q.front(); q.pop();
            //     count++;
    
            //     if(currNode->left) q.push(currNode->left);
            //     if(currNode->right) q.push(currNode->right);
                
            // }
            // return count;
        }
    };