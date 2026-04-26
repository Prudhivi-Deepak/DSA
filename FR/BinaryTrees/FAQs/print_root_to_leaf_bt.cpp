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
        vector<vector<int>> AllPaths;
        void dfs(TreeNode *root, vector<int> &traversal){
            // cout << root->data << endl;
            traversal.push_back(root->data);

            if(root->left == nullptr && root->right == nullptr){
                AllPaths.push_back(traversal);
                traversal.pop_back();
                return;
            }

            if(root->left) dfs(root->left, traversal);
            if(root->right) dfs(root->right, traversal);
            traversal.pop_back();
        }

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<int> traversal;
            dfs(root, traversal);
            return AllPaths;
		}
};