
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root==nullptr) return {};
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> zigzagTraversal;
            bool leftToRight = true;
    
            while(!q.empty()){
                int size_in_current_level = q.size();
                vector<int> zigzagLeveLTraversal(size_in_current_level);
    
                for(int i=0; i<size_in_current_level; i++){
                    TreeNode *currNode = q.front();q.pop();
                    int index = leftToRight ? i : size_in_current_level-i-1;
                    zigzagLeveLTraversal[index] = currNode->val;
    
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
    
                }
                leftToRight = !leftToRight;
                zigzagTraversal.push_back(zigzagLeveLTraversal);
            }
            return zigzagTraversal;
        }
    };