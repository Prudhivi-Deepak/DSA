/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:

    vector<int> topView(TreeNode *root){
        //your code goes here

        queue<pair<TreeNode *,int>> q;
        q.push({root, 0});
        map<int,int> umap;
        

        while(!q.empty()){
            auto [currNode, col] = q.front(); q.pop();
            if(umap.find(col)==umap.end()) umap[col] = currNode->data;

            if(currNode->left) q.push({currNode->left, col-1});
            if(currNode->right) q.push({currNode->right, col+1});
            
        }

        vector<int> ans;

        for(auto it=umap.begin(); it!=umap.end(); it++){
            ans.push_back(it->second);
        }

        return ans;

    }
};