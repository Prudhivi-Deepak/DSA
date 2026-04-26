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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //your code goes here

        if(root == nullptr) return nullptr;

        if(key < root->data){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->data){
            root->right = deleteNode(root->right, key);
        }
        else {
            // if key equal curr node
            // if left node is empty just replace current Node with it's right value
            if(root->left == nullptr) {
                TreeNode *rootRight = root->right;
                delete root;
                return rootRight;
            }
            // if right is empty and lef tis not empty replace the left part with curr Node
            if(root->right == nullptr) {
                TreeNode *rootLeft = root->left;
                delete root;
                return rootLeft;
            }

            // else it measn both rigth and left are there, node we get the immediate successor of currNode
            // TreeNode * successor = getImmediateSuccessor(root, root->right);

            TreeNode *RightSuccessorParent = root;
            TreeNode *successor = root->right;

            while(successor ->left !=nullptr){
                RightSuccessorParent = successor;
                successor = successor->left;
            }

            root->data = successor->data;

            // after this we will have successor with left (nullptr) and right (nullptr or node)
            // successor parent --> left or right is successor

            // we know successor left is a nullptr, but not sure about right
            if(RightSuccessorParent->right == successor){
                RightSuccessorParent -> right = successor->right;
            }
            else{
                RightSuccessorParent ->left = successor -> right;
            }
            delete successor; //delete the successor
        }
        return root;
    }
};