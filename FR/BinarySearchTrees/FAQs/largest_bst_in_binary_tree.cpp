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

        // return max size of BST 

        tuple<int,int,int> LargestBSTHelper(TreeNode *root){

            if(root == nullptr){
                // return size, minValue, maxValue
                // 0, valid minValue(INT_MAX), valid maxValue (INT_MIN)
                return {0, INT_MAX, INT_MIN};
            }

            auto [leftSize, leftMin, leftMax] = LargestBSTHelper(root->left);
            auto [rightSize, rightMin, rightMax] = LargestBSTHelper(root->right);

            // valid bst means leftMax < currNode < rightMin
            if(leftMax < root->data && root->data < rightMin){
                // valid bst return total size and valid boundaries
                return {leftSize+rightSize+1, min(leftMin, root->data), max(rightMax, root->data)};
            }
            
            // not valid bst return valid best bst size with invalid boundaries to pass to upper
            return {max(leftSize, rightSize), INT_MIN, INT_MAX};
        }

		int largestBST(TreeNode* root){
			//your code goes here
            return get<0>(LargestBSTHelper(root));
		}
};