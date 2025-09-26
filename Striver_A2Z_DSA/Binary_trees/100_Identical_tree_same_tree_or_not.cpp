
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
        bool Inorder(TreeNode * root1, TreeNode* root2){
            if(root1==nullptr && root2==nullptr) return true;
            if((root1==nullptr && root2!=nullptr) || (root1!=nullptr && root2==nullptr) || root1->val!=root2->val) return false;
            bool left = Inorder(root1->left, root2->left);
            bool right = Inorder(root1->right, root2->right);
            return left && right;
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return Inorder(p, q);
        }
    };