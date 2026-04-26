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
    TreeNode *BT(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &inorder_index_map,
        int postStart, int postEnd, int inordStart, int inordEnd){

        if(postEnd < postStart || inordEnd < inordStart ) return nullptr;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inorder_index = inorder_index_map[postorder[postEnd]];
        int inorder_len = inorder_index - inordStart;

        root->left = BT(inorder, postorder, inorder_index_map,
                        postStart, postStart+inorder_len-1,
                        inordStart,           inorder_index-1);

        root->right = BT(inorder, postorder, inorder_index_map,
                        postStart+inorder_len,  postEnd-1,
                        inorder_index+1,          inordEnd);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //your code goes here

        unordered_map<int,int> inorder_index_map;

        for(int i=0; i<inorder.size(); i++){
            inorder_index_map[inorder[i]] = i;
        }

        return BT(inorder, postorder, inorder_index_map, 0, postorder.size()-1, 0, inorder.size()-1);

    }
};