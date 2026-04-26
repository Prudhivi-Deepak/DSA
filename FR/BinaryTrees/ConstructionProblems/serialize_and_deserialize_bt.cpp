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

    string serialize(TreeNode* root) {
        string serializedString = "";

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            auto currNode = q.front(); q.pop();

            if(currNode == nullptr){
                serializedString += "#,"; continue;
            }
            else
                serializedString += to_string(currNode->data)+',';

            q.push(currNode->left);
            q.push(currNode->right);
        }
        return serializedString;

    }

    TreeNode* deserialize(string data) {
        if(data == "" || data == "#" || data.empty()) return nullptr;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto currNode = q.front(); q.pop();

            getline(ss, str, ',');
            if(str!="#"){
                currNode->left = new TreeNode(stoi(str));
                q.push(currNode->left);
            }

            getline(ss, str, ',');
            if(str!="#"){
                currNode->right = new TreeNode(stoi(str));
                q.push(currNode->right);
            }
        }        
        return root;
    }
};


/*
* Your Codec object will be instantiated and called as such:
* Codec* ser = new Codec();
* Codec* deser = new Codec();
* string tree = ser->serialize(root);
* TreeNode* ans = deser->deserialize(tree);
* return ans;
*/