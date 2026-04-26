/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:

        int UpperBound(TreeNode* root,int key){
            int key_index = -1;
            while(root){
                if(root->data >= key){
                    // > value then key --> assign it
                    key_index = root->data;
                    root = root->left;
                }
                else{
                    root = root->right;
                }
            }
            return key_index;
        }

        int lowerBound(TreeNode *root, int key){
            int key_index = -1;

            while(root){
                if(root->data > key){
                    root = root->left;
                }
                else{
                    key_index = root->data;
                    root = root->right;
                }
            }
            return key_index;
        }

		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            // floor just lower value for given key
            // ceil just higher value for given key

            // upper bound - index with value > given key
            // lower bound - index with value >= given key

            // floor - find lower bound and then -1 of that index
            // ceil - find upper bound and return that
            return vector<int>{lowerBound(root, key), UpperBound(root, key)};
		}
};