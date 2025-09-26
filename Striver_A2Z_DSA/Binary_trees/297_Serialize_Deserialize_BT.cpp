
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

class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(root==nullptr) return "";
    
            queue<TreeNode*> q;
            q.push(root);
            string serializedString = "";
    
            while(!q.empty()){
                TreeNode * currNode = q.front(); q.pop();
                if(currNode == nullptr){
                    serializedString += "#,";
                }
                else{
                    serializedString += to_string(currNode->val) + ',';
                    q.push(currNode->left);
                    q.push(currNode->right);
                }
            }
            // cout << serializedString << endl;
            return serializedString;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data.empty()) {
                return nullptr;
            }
    
            stringstream s(data);
            string str;
            getline(s, str, ',');
    
            TreeNode *root = new TreeNode(stoi(str));
            queue<TreeNode*> q; q.push(root);
            int left, right;
    
            while(!q.empty()){
                TreeNode *currNode = q.front(); q.pop();
                getline(s, str, ',');
                if(str!="#"){
                    currNode->left = new TreeNode(stoi(str));
                    q.push(currNode->left);
                }
                getline(s, str, ',');
                if(str!="#"){
                    currNode->right = new TreeNode(stoi(str));
                    q.push(currNode->right);
                }
                
            }
    
            return root;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));