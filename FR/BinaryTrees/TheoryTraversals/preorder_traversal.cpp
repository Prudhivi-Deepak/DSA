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
		vector<int> ans;
		void pre_helper(TreeNode *root){
			if(root== nullptr) return;
			ans.push_back(root->data);
			pre_helper(root->left);
			pre_helper(root->right);
		}

		vector<int> preorder(TreeNode* root){
	       //your code goes here
		   pre_helper(root);
		   return ans;
		}
};