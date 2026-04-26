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
        TreeNode *findRightNode(TreeNode *rootNode, TreeNode *LeftNode, vector<int> &morris_preorder){

            while(LeftNode->right){

                if(LeftNode->right == rootNode){
                    LeftNode->right = nullptr;
                    return rootNode->right;
                }
                LeftNode = LeftNode->right;
            }

            LeftNode ->right = rootNode;
            morris_preorder.push_back(rootNode->data);
            return rootNode->left;
        }

		vector<int> preorder(TreeNode* root){
	       //your code goes here

           vector<int> morris_preorder;

           while(root!=nullptr){
        
            if(root->left){
                root = findRightNode(root, root->left, morris_preorder);
            }
            else{
                morris_preorder.push_back(root->data);
                root = root->right;
            }
           }
           return morris_preorder;
		}
};