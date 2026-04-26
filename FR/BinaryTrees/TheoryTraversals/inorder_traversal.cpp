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
		vector<int> Inord;
		void inorder_helper(TreeNode *root){
			if(root==nullptr) return;
			inorder_helper(root->left);
			Inord.push_back(root->data);
			inorder_helper(root->right);
		}
		vector<int> inorder(TreeNode* root){
	        //your code goes here
			inorder_helper(root);
			return Inord;
		}
};