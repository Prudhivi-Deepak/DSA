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
    TreeNode *firstNode = nullptr, *middleNode = nullptr, *lastNode = nullptr, *prev = nullptr; 
    void inorder(TreeNode *root){
        if(root==nullptr) return ;

        inorder(root->left);

        if(prev && prev->data > root->data){
            if(firstNode == nullptr){
                firstNode = prev;
                middleNode = root;
            }
            else{
                lastNode = root;
                // return;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
       //your code goes here

        // 1 < 2  < 4 > 3 < 5 < 6 < 7 < 8 < 9 --> case 1 : side by side nodes swapped
        // 1 < 2 < 7 > 4 < 5 < 6  > 3 > 8 > 9 --> case 2 : nodes with far dist nodes swapped

        inorder(root);

        if(firstNode == nullptr) return;

        if(firstNode && lastNode){
            // swap first and lastNode
            int temp = firstNode->data;
            firstNode->data = lastNode->data;
            lastNode->data = temp;
        }
        else{
            int temp = firstNode->data;
            firstNode->data = middleNode->data;
            middleNode->data = temp;
        }

    }
};