/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode * findRightMostNode_Or_ReturnLeft(TreeNode *RootNode, TreeNode *LeftNode, vector<int> &morris_inorder){

        while(LeftNode->right){
            if(LeftNode-> right == RootNode){
                morris_inorder.push_back(RootNode->data);
                LeftNode->right = nullptr;
                return RootNode->right;
            }
            LeftNode = LeftNode->right;
        }
        LeftNode->right = RootNode;
        return RootNode->left;
    }

    vector<int> getInorder(TreeNode* root) {
    	//your code goes here

        vector<int> morris_inorder;

        while(root!=nullptr){

            if(root->left){
                root = findRightMostNode_Or_ReturnLeft(root, root->left, morris_inorder);
            }
            else{
                morris_inorder.push_back(root->data);
                root = root->right;
            }
        }
        return morris_inorder;
    }
};