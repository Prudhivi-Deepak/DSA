
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
        TreeNode *markNextNode(TreeNode *StartNode, TreeNode *root, vector<int> &preorder_morris_traversal){
            
            while(root->right){
                if(root->right == StartNode){
                    root->right = nullptr;
                    return StartNode->right;
                }
                root = root->right;
            }

            root->right = StartNode;
            preorder_morris_traversal.push_back(StartNode->val);
            return StartNode->left;

        }
		vector<int> preorder(TreeNode* root){
	       //your code goes here
           vector<int> preorder_morris_traversal;
           while(root!=nullptr){
                if(root->left==nullptr){
                    preorder_morris_traversal.push_back(root->val);
                    root = root->right;
                }
                else{
                    root = markNextNode(root, root->left, preorder_morris_traversal);
                }
           }
           return preorder_morris_traversal;
		}
};