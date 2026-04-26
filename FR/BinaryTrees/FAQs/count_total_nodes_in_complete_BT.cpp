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
    int countLeft(TreeNode *root){
        int cnt = 0;
        while(root){
            root = root->left; cnt++;
        }
        return cnt;
    }

    int countRight(TreeNode *root){
        int cnt = 0;
        while(root){
            root = root->right; cnt++;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) { 

        int leftH = countLeft(root);
        int rightH = countRight(root);

        if(leftH == rightH) return (1<<leftH)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countNodes1(TreeNode* root) { 
        //your code goes here

        int ans = 0;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            auto currNode = q.front(); q.pop();
            ans++;

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);

        }
        return ans;
    }
};