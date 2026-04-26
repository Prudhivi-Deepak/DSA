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
    int maxDepth(TreeNode* root) {
        //your code goes here
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        int ans = 0;

        while(!st.empty()){
            auto [curr, path] = st.top(); st.pop();
            ans = max(ans, path);

            if(curr->left) st.push({curr->left, path+1});
            if(curr->right) st.push({curr->right, path+1});
        }
        return ans;
    }
};