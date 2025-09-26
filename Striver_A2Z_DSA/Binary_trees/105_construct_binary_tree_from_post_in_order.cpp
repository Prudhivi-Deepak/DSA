
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* BT(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &inorder_ind){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        TreeNode *newNode = new TreeNode(preorder[preStart]);
        newNode->left = BT(preStart+1, 
                            preStart+inorder_ind[preorder[preStart]]-inStart, 
                            inStart, 
                            inStart+inorder_ind[preorder[preStart]]-1, 
                            preorder, inorder, inorder_ind);
        newNode->right = BT(preStart+ inorder_ind[preorder[preStart]] - inStart+1,
                            preEnd, 
                            inorder_ind[preorder[preStart]]+1, 
                            inEnd, 
                            preorder, inorder, inorder_ind);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorder_ind;

        for(int i=0; i<inorder.size(); i++){
            inorder_ind[inorder[i]] = i;
        }

        return BT(0, preorder.size()-1, 0, inorder.size(), preorder, inorder, inorder_ind);
    }
};