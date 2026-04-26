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
    int maxDia = 0;

    int diameter(TreeNode *root){

        if(root==nullptr) return 0;

        int left = diameter(root->left);
        int right = diameter(root->right);

        maxDia = max(maxDia, left+right);

        return max(left, right) + 1;       
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
        // take left path sum , right path sum and curr node = some dia sum
        // now return the max of left path sum , right path sum + currNode sum and recursively take max dia
        diameter(root);
        return maxDia;
    }
};