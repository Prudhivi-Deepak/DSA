
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
        TreeNode *BT(int postStart, int postEnd, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inorder_ind){
            if(postStart > postEnd || inStart > inEnd) return nullptr;
    
            TreeNode *newNode = new TreeNode(postorder[postEnd]);
    
            int inInd = inorder_ind[postorder[postEnd]];
            int LeftCount = inInd - inStart;
    
            newNode->left = BT(
                postStart,
                postStart+LeftCount-1,
                inStart,
                inInd-1,
                inorder, postorder, inorder_ind
            );
            
            newNode->right = BT(
                postStart+LeftCount,
                postEnd-1,
                inInd+1,
                inEnd,
                inorder, postorder, inorder_ind
            );
    
            return newNode;
    
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> inorder_ind;
    
            for(int i=0; i<inorder.size(); i++){
                inorder_ind[inorder[i]] = i;
            }
    
            return BT(0, postorder.size()-1, 0, inorder.size()-1, inorder, postorder, inorder_ind);
        }
    };