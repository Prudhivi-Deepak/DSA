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

    // void rightT(TreeNode *root, vector<int> &rightTraversal){
    //     if(root==nullptr) return;

    //     rightTraversal.push_back(root->data);

    //     if(root->right){
    //         rightT(root->right, rightTraversal);
    //     }
    //     else{
    //         rightT(root->left, rightTraversal);
    //     }
    // }

    vector<int> rightSideView(TreeNode* root) {
        //your code goes here

        queue<pair<TreeNode *, int>> q; //node, level
        q.push({root, 0});
        
        map<int,int> umap;

        while(!q.empty()){
            auto [currNode, level] = q.front(); q.pop();

            umap[level] = currNode->data;

            if(currNode->left) q.push({currNode->left, level+1});
            if(currNode->right) q.push({currNode->right, level+1});
        }

        vector<int> ans;

        for(auto it=umap.begin(); it!=umap.end(); it++){
            ans.push_back(it->second);
        }

        return ans;


        // vector<int> rightTraversal;
        // rightT(root, rightTraversal);
        // return rightTraversal;

    }
};