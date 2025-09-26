
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
        int findMaxPath(TreeNode *root, int &maxsum){
    
            if(root == nullptr) return 0;
    
            int leftPathSum = max(0, findMaxPath(root->left, maxsum));
            int rightPathSum = max(0, findMaxPath(root->right, maxsum));
    
            maxsum =  max(leftPathSum+rightPathSum+root->val, maxsum);
            return max(leftPathSum, rightPathSum)+root->val;
        }
        int maxPathSum(TreeNode* root) {
            int maxsum = INT_MIN;
            findMaxPath(root,maxsum);
            return maxsum;
        }
    };