
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

class BSTIteratorFromLeft{
    public:
        stack<TreeNode *> st;
        BSTIteratorFromLeft(TreeNode* root){
            while(root!=nullptr){
                st.push(root);root = root->left;
            }
        }
    
        bool hasNext(){
            return !st.empty();
        }
    
        int next(){
            TreeNode *currNode = st.top(); st.pop();
            TreeNode *tempNode = currNode->right;
            while(tempNode!=nullptr){
                st.push(tempNode);tempNode = tempNode->left;
            }
            return currNode->val;
        }
    };
    
    class BSTIteratorFromRight{
    public:
        stack<TreeNode *> st;
        BSTIteratorFromRight(TreeNode* root){
            while(root!=nullptr){
                st.push(root);root = root->right;
            }
        }
    
        bool hasNext(){
            return !st.empty();
        }
    
        int next(){
            TreeNode *currNode = st.top(); st.pop();
            TreeNode *tempNode = currNode->left;
            while(tempNode!=nullptr){
                st.push(tempNode);tempNode = tempNode->right;
            }
            return currNode->val;
        }
    };
    class Solution {
    public:
        bool findTarget(TreeNode* root, int k) {
            BSTIteratorFromLeft LeftItr(root);
            BSTIteratorFromRight RightItr(root);
    
            int leftP = LeftItr.next();
            int rightP = RightItr.next();
    
            // apply normal Two sum logic
            while(leftP < rightP){
    
                if(leftP + rightP == k){
                    return true;
                }
                else if(leftP + rightP < k){
                    leftP = LeftItr.next();
                }
                else{
                    rightP = RightItr.next();
                }
            }
    
            return false;
        }
    };