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
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
		//your code goes here
        unordered_map<TreeNode *,TreeNode *> umap;

        queue<pair<TreeNode *, TreeNode*>> q; //node, parentNode

        q.push({root, nullptr});

        while(!q.empty()){
            auto [currNode, parentNode] = q.front(); q.pop();

            umap[currNode] = parentNode;

            if(currNode->left) q.push({ currNode->left, currNode });
            if(currNode->right) q.push({ currNode->right, currNode });
            
        }

        // parent map is ready now, traverse from taget node to k distanceK
        vector<int> ans;

        queue<pair<TreeNode *, int>> q1;
        unordered_map<TreeNode *, bool> visited;

        q1.push({target, 0});
        visited[target] = true;

        while(!q1.empty()){

            auto [currNode, path] = q1.front(); q1.pop();

            if(path == k){
                ans.push_back(currNode->data); continue;
            }

            if(currNode->left && visited[currNode->left]!=true ) {
                q1.push({currNode->left, path+1});
                visited[currNode->left] = true;
            }
            if(currNode->right && visited[currNode->right]!=true) {
                q1.push({currNode->right, path+1});
                visited[currNode->right] = true;
            }
            if(umap.find(currNode)!=umap.end() && umap[currNode] && visited[umap[currNode]]!=true ) {
                q1.push({umap[currNode], path+1});
                visited[umap[currNode]] = true;
            }

        }
        return ans;
    }
};