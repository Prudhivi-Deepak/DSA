
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
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            if(root == nullptr) return {};
            unordered_map<TreeNode *, TreeNode *> umap;
            queue<TreeNode *> q;
            q.push(root);
    
            while(!q.empty()){
    
                int size = q.size();
                for(int i=0; i<size; i++){
                    TreeNode *currNode = q.front(); q.pop();
                    // cout << currNode << endl;
                    if(currNode->left) {
                        umap[currNode->left] = currNode; q.push(currNode->left);
                        // cout << currNode->left->data << umap[currNode->left]->data << endl;
                    }
                    if(currNode->right) {
                        umap[currNode->right] = currNode; q.push(currNode->right);
                        // cout << currNode->right->data << umap[currNode->right]->data << endl;
                    }
                }
            }
    
            q.push(target);
            int dist = 0;
            unordered_map<TreeNode *, bool> visited;
            visited[target] = true;
    
            while(!q.empty()){
                if(dist==k) break;
                int size = q.size();
                for(int i=0; i<size; i++){
                    TreeNode *currNode = q.front(); q.pop();
                    if(currNode->left && visited.find(currNode->left) == visited.end()) {
                        q.push(currNode->left); visited[currNode->left] = true;
                    }
                    if(currNode->right && visited.find(currNode->right) == visited.end()) {
                        q.push(currNode->right);visited[currNode->right] = true;
                    }
                    if(umap.find(currNode) != umap.end() && visited.find(umap[currNode]) == visited.end()){
                        q.push(umap[currNode]); visited[umap[currNode]] = true;
                    }
                }
                dist++;
                // cout << "dist :"<< dist << endl;
                // printQueue(q);            
            }
            
            vector<int> kDistNodes;
            while(!q.empty() && q.front()!=nullptr){
                kDistNodes.push_back(q.front()->val); q.pop();
            }
            return kDistNodes;
        }
    };