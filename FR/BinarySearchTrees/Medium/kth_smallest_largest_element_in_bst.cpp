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
    int lk = 0, sk = 0, Largest = -1, smallest = -1;
    void kthSmallest(TreeNode *root, int k){
        if(root == nullptr) return ;
        kthSmallest(root->left, k);
        lk++;
        if(lk == k) {smallest = root->data; return;}
        kthSmallest(root->right, k);
    }

    void kthLargest(TreeNode *root, int k){
        if(root == nullptr) return ;
        kthLargest(root->right, k);
        sk++;
        if(sk == k) {Largest = root->data; return;}
        kthLargest(root->left, k);
    }

	vector<int> kLargesSmall(TreeNode* root,int k){
		//your code goes here
        kthSmallest(root, k);
        kthLargest(root, k);
        return vector<int>{smallest, Largest};
	}
};