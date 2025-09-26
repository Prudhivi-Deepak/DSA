
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
        int widthOfBinaryTree(TreeNode* root) {
            queue<pair<TreeNode *, long long>> q;
    
            q.push({root, 0});
            int bottom_level_first_index = -1, bottom_level_last_index = -1, max_width_all_levels = -1;
    
            while(!q.empty()){
    
                //pop all nodes in queue (prev level nodes)
                int size = q.size();
                int min_index = q.front().second;
                // cout << q.front().first->val << " : " << min_index << endl;
                for(int i=0; i<size; i++){
    
                    auto [currNode, node_index] = q.front(); q.pop();
                    //take first node index at every level - 0 always i guess;
                    node_index = node_index - min_index;
    
                    if(i==0) bottom_level_first_index = node_index;
                    //take last index at every level till we reach bottom level
                    if(i==size-1) bottom_level_last_index = node_index;
    
                    // cout << " : : " << currNode->val << " : " << node_index << endl;
    
                    if(currNode->left) q.push({currNode->left, 2*node_index});
                    if(currNode->right) q.push({currNode->right, 2*node_index+1});
    
                    //callculate max width among all levels not just bottom level;
                    max_width_all_levels = max(max_width_all_levels,  bottom_level_last_index - bottom_level_first_index +1);
    
                }
            }
    
            return max_width_all_levels;
        }
    };