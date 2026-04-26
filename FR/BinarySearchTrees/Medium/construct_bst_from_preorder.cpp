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
    TreeNode *BT1(vector<int> &preorder, vector<int> &inorder, 
        int inStart, int inEnd, int preStart, int preEnd, unordered_map<int,int> &inord_ind_map){

        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        TreeNode *currNode = new TreeNode(preorder[preStart]);

        int inorder_index = inord_ind_map[inorder[preStart]];
        int inorder_len = inorder_index - inStart;

        currNode->left = BT1(preorder, inorder,
                    preStart+1, preStart+inorder_len,
                    inStart, inorder_index-1,
                    inord_ind_map
                );
        
        currNode ->right = BT1(preorder, inorder,
                    preStart+inorder_len+1, preEnd,
                    inorder_index+1, inEnd,
                    inord_ind_map
                );
        return currNode;
    }

    TreeNode *BT(vector<int> &preorder, int minValue, int maxValue, int &index){

        if(index >= preorder.size() || preorder[index] < minValue || preorder[index] > maxValue) return nullptr;

        TreeNode *root = new TreeNode(preorder[index++]);

        root->left = BT(preorder, minValue, root->data, index);
        root->right = BT(preorder, root->data, maxValue, index);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //your code goes here
        int index = 0;
        return BT(preorder, -1, 1001, index);

        // vector<int> inorder = preorder;
        // sort(inorder.begin(), inorder.end());

        // unordered_map<int,int> inord_ind_map;
        // for(int i=0; i<inorder.size(); i++){
        //     inord_ind_map[inorder[i]] = i;
        // }
        // return BT(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1, inord_ind_map);
    }
};