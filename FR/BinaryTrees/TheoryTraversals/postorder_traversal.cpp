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
		void post_helper(TreeNode *root){
			if(root==nullptr) return;
			post_helper(root->left);
			post_helper(root->right);
			ans.push_back(root->data);
		}

		vector<int> postorder(TreeNode* root){
	        //your code goes here
			post_helper(root);
			return ans;
		}
};