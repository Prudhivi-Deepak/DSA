
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
        TreeNode *BuildBSTWithUB(vector<int>& preorder, int &ps, int ub){
    
            if( ps == preorder.size() || preorder[ps]>ub) return nullptr;
            
            TreeNode *newNode = new TreeNode(preorder[ps++]);
    
            newNode->left = BuildBSTWithUB(
                preorder, ps, newNode->val
            );
    
            newNode->right = BuildBSTWithUB(
                preorder, ps, ub
            );
            return newNode;
    
        }
    
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int ps = 0;
            return BuildBSTWithUB(preorder, ps, INT_MAX);
        }
    
        TreeNode *BuildBST(vector<int> &pre, vector<int> &inord, int preS, int preE, int inS, int inE, unordered_map<int,int> inorder_map){
            if(preS > preE || inS > inE) return nullptr;
    
            // create a root node which is PreS
            TreeNode *newNode = new TreeNode(pre[preS]);
    
            int numsLeft = inorder_map[pre[preS]]-inS;
    
            newNode->left = BuildBST(
                pre, inord,
                preS+1, preS+numsLeft,
                inS, inorder_map[pre[preS]]-1,
                inorder_map
            );
    
            newNode->right = BuildBST(
                pre, inord,
                preS+numsLeft+1, preE,
                inorder_map[pre[preS]]+1, inE,
                inorder_map
            );
    
            return newNode;
    
        }
        
        TreeNode* bstFromPreorderUsingInorder(vector<int>& preorder) {
            //your code goes here
            unordered_map<int,int> inorder_map;
            vector<int> inorder = preorder;
            sort(inorder.begin(), inorder.end());
    
            for(int i=0; i<inorder.size(); i++){
                inorder_map[inorder[i]] = i;
            }
    
            return BuildBST(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inorder_map);
        }
    };