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
    void LevelOrderTraversal(TreeNode *root, vector<vector<int>> &levelOrder, int level){
        if(root==nullptr) return;

        // cout << levelOrder.size() << " : " << level << " = " << root->data << endl;

        if(levelOrder.size() == level){
            levelOrder.push_back({root->data});
        }
        else{
            levelOrder[level].push_back(root->data);
        }

        LevelOrderTraversal(root->left, levelOrder, level+1);
        LevelOrderTraversal(root->right, levelOrder, level+1);

    }

    vector<vector<int> > levelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>> levelOrder;
        LevelOrderTraversal(root, levelOrder, 0);
        return levelOrder;
    }
};