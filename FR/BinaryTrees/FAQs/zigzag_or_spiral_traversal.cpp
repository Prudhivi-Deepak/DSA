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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>> ZigZag;
        bool LTR = true;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){

            int qSize = q.size();
            vector<int> rowLevel(qSize);
            for(int i=0; i<qSize; i++){
                auto currNode = q.front();q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                // rowLevel.push_back(currNode->data);
                int index = LTR ? i : qSize-i-1;
                rowLevel[index] = currNode->data;
            }

            // if(LTR){
            ZigZag.push_back(rowLevel);
            // }
            // else{
            //     reverse(rowLevel.begin(), rowLevel.end());
            //     ZigZag.push_back(rowLevel);
            // }

            LTR = !LTR;
        }
        return ZigZag;
    }
};