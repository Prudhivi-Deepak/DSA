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
        bool isValid(TreeNode *root, int minValue, int maxValue){

            if(root == nullptr) return true;
            
            return ((minValue < root->data || root->data == INT_MIN ) && (root->data < maxValue  || root->data == INT_MAX))
            && isValid(root->left, minValue, root->data)
            && isValid(root->right, root->data, maxValue);

        }

		bool isBST(TreeNode* root){
			//your code goes here

            // go to right update minvalue, go to left update maxvalue

            int minValue = INT_MIN, maxValue = INT_MAX;
            return isValid(root, minValue, maxValue);
            // if(root==nullptr) return true;
            // bool isLeft = true, isRight = true;
            // if(root->left) isLeft = root->left->data < root->data;
            // if(root->right) isRight = root->right->data > root->data;

            // return isLeft && isRight && isBST(root->left) && isBST(root->right);
		}
};