/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:

    int Height(TreeNode *root){

        if(root==nullptr) return 0;

        int LH = Height(root->left);
        if(LH==-1) return -1;
        int RH = Height(root->right);
        if(RH==-1) return -1;

        if(abs(LH-RH)>1) return -1;

        return max(LH, RH)+1;
    }

    bool isBalanced(TreeNode *root){
    	//your code goes here
        return Height(root)!=-1;
    }
};