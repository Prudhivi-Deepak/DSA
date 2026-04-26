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

    int PathSum = INT_MIN;

    int largePathSum(TreeNode *root){

        if(root==nullptr) return 0;

        int leftPathSum = largePathSum(root->left);
        if(leftPathSum<0) leftPathSum = 0;
        int rightPathSum = largePathSum(root->right);
        if(rightPathSum<0) rightPathSum = 0;

        PathSum = max({PathSum, leftPathSum + rightPathSum + root->data});

        return max(leftPathSum, rightPathSum) + root->data;
    }

    int maxPathSum(TreeNode* root) {
        //your code goes here
        largePathSum(root);
        return PathSum;
    }
};	