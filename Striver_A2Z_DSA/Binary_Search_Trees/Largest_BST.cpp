
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
        vector<int> postorder(TreeNode *root){
            if(root==nullptr)
                return {0, INT_MAX, INT_MIN};

            vector<int> left = postorder(root->left);
            vector<int> right = postorder(root->right);
            int leftmax = left[2]; 
            int rightmin = right[1];
            if(leftmax < root->val  && root->val < rightmin){
                return {left[0] + right[0]+1, min(root->val, left[1]), max(root->val, right[2])};
            }

            return {max(left[0], right[0]), INT_MIN, INT_MAX};
        }

		int largestBST(TreeNode* root){
			//your code goes here
            int LargestBSTLength = postorder(root)[0];
            return LargestBSTLength;
		}
};