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
    TreeNode* BT(vector<int>& preorder, vector<int>& inorder, 
        unordered_map<int, int> &inord_index_map, 
        int preStart, int preEnd, int inordStart, int indordEnd){

        if(preStart > preEnd || inordStart > indordEnd) return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inorder_index = inord_index_map[preorder[preStart]];
        int inorder_len = inorder_index - inordStart;

        root->left = BT(preorder, inorder, inord_index_map,
                    preStart+1, preStart + inorder_len,
                    inordStart, inorder_index-1);

        root->right = BT(preorder, inorder, inord_index_map,
            preStart + inorder_len + 1, preEnd,
            inorder_index +1, indordEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here
        unordered_map<int, int> inord_index_map;

        for(int i=0; i<inorder.size(); i++){
            inord_index_map[inorder[i]] = i;
        }

        return BT(preorder, inorder, inord_index_map,
            0, preorder.size()-1,
            0, inorder.size()-1);

    }
};