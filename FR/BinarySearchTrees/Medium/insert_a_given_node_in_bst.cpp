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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //your code goes here

        TreeNode *Root = root;

        while(Root){
            if(val < Root->data){
                if(Root->left == nullptr){
                    Root->left = new TreeNode(val);
                    // return root;
                    break;
                }
                Root = Root->left;
            }
            else if(val > Root->data){
                if(Root->right == nullptr){
                    Root->right = new TreeNode(val);
                    // return root;
                    break;
                }
                Root = Root->right;
            }
        }
        return root;
    }
};