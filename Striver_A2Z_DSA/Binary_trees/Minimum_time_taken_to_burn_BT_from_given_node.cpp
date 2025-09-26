
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

 class Solution{
	public:
		int timeToBurnTree(TreeNode* root, int start){
            //your code goes here
            unordered_map<TreeNode*, TreeNode*> parentsMap;
            queue<TreeNode*> q;
            TreeNode *target;

            q.push(root);
            while(!q.empty()){
                int size = q.size();
                // for(int i=0; i<size; i++){
                TreeNode *currNode = q.front(); q.pop();
                if(currNode->data == start) target = currNode;

                if(currNode->left){ parentsMap[currNode->left] = currNode; q.push(currNode->left);}
                if(currNode->right){ parentsMap[currNode->right] = currNode; q.push(currNode->right);}
                // }
            }

            q.push(target);
            unordered_set<TreeNode*> visited; visited.insert(target);
            int time = -1;

            while(!q.empty()){
                int size = q.size();
                for(int i=0; i<size; i++){
                    TreeNode *currNode = q.front(); q.pop();

                    if(currNode->left && visited.find(currNode->left)==visited.end()) {
                        q.push(currNode->left); visited.insert(currNode->left);
                    }
                    if(currNode->right && visited.find(currNode->right)==visited.end()) {
                        q.push(currNode->right); visited.insert(currNode->right);
                    }
                    if(parentsMap.find(currNode)!=parentsMap.end() && visited.find(parentsMap[currNode])==visited.end()){
                        q.push(parentsMap[currNode]); visited.insert(parentsMap[currNode]);
                    }
                }
                time++;
            }

            return time;
		}	
};