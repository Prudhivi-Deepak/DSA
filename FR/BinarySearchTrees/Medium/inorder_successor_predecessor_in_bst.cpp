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
        int successor = -1, predecessor = -1;
        TreeNode *prev = nullptr;

        void inord_successor(TreeNode *root, int key){
            if(root==nullptr) return;

            inord_successor(root->left, key);
            if(prev && prev->data == key ){
                successor = root->data;
                return;
            }
            prev = root;
            inord_successor(root->right, key);
        }

        void inord_predecessor(TreeNode *root, int key){
            if(root==nullptr) return;

            inord_predecessor(root->left, key);
            if(root->data == key ){
                predecessor = prev->data;
                return;
            }
            prev = root;
            inord_predecessor(root->right, key);
        }

        void inord_bst_successor(TreeNode *root, int key){
            if(root==nullptr) return;

            if(key < root->data){
                successor = root->data;
                inord_bst_successor(root->left, key);
            }
            else{
                inord_bst_successor(root->right, key);
            }
        }

        void inord_bst_predecessor(TreeNode *root, int key){
            if(root == nullptr) return;

            // predecessor --> left subtree right most element
            if(key > root->data){
                predecessor = root->data;
                inord_bst_predecessor(root->right, key);
            }
            else{
                inord_bst_predecessor(root->left, key);
            }
        }

		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here
            // inord_successor(root, key);
            // prev = nullptr;
            // inord_predecessor(root, key);
            inord_bst_predecessor(root, key);
            inord_bst_successor(root, key);
            return vector<int>{predecessor, successor};

		}
};