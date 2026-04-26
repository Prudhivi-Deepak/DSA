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
    long long int widthOfBinaryTree(TreeNode* root) {
        //your code goes here
        //        1
        //    1      2
        //  1   2   3   4
        // 1 2 3 4 5 6 7 8

        //    1
        //  2    3
        //n  4 5

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        int maxWidth = 1;

        while(!q.empty()){

            int qSize = q.size();
            int firstWidth = 0, lastWidth = 0;

            for(int i=0; i<qSize; i++){

                auto [currNode, nodes] =  q.front(); q.pop();

                if(i==0) firstWidth = nodes;
                if(i==qSize-1) lastWidth = nodes;

                if(currNode->left) q.push({currNode->left, 2*nodes-1});
                if(currNode->right) q.push({currNode->right, 2*nodes});
            }
            maxWidth = max(maxWidth, lastWidth-firstWidth+1);
        }
        return maxWidth;
    }
};