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
    void leftBoundary(TreeNode *root, vector<int> &boundary){

        if(root->left == nullptr && root->right==nullptr) return;

        boundary.push_back(root->data);
        if(root->left){
            leftBoundary(root->left, boundary);
        }
        else if(root->right){
            leftBoundary(root->right, boundary);
        }

    }

    void bottomBoundary(TreeNode *root, vector<int> &boundary){
        if(root->left == nullptr && root->right==nullptr){
            boundary.push_back(root->data);
            return;
        }
        if(root->left) bottomBoundary(root->left, boundary);
        if(root->right) bottomBoundary(root->right, boundary);
    }

    void rightBoundary(TreeNode *root, vector<int> &boundary){
        if(root->left == nullptr && root->right==nullptr) return;

        boundary.push_back(root->data);
        if(root->right){
            rightBoundary(root->right, boundary);
        }
        else if(root->left){
            rightBoundary(root->left, boundary);
        }
    }

    vector <int> boundary(TreeNode* root){
    	//your code goes here
        if(root==nullptr) return {};
        vector<int> ans;
        ans.push_back(root->data);
        if(root->left) leftBoundary(root->left, ans);
        if(root->left || root->right) bottomBoundary(root, ans);
        vector<int> right;
        if(root->right) rightBoundary(root->right, right);
        reverse(right.begin(), right.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};