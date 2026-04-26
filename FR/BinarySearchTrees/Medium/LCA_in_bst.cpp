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
		TreeNode* lca(TreeNode* root, int p, int q){
	        //your code goes here

            if(root == nullptr) return nullptr;

            if(p < root->data && q < root->data) return lca(root->left, p, q);
            if(p > root->data && q > root->data) return lca(root->right, p, q);

            return root;            

            // if(root == nullptr) return nullptr;
            // if(root->data == p || root->data == q) return root;

            // TreeNode * Left = lca(root->left, p, q);
            // TreeNode * right = lca(root->right, p, q);

            // if(Left && right) return root;

            // if(Left) return Left;
            // if(right) return right;

            // return nullptr;
		}
};