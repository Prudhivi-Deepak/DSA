#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    void inorder(Node *root, map<int,pair<int,int>> &m, int col, int row){
        if(root==nullptr) return;
        // cout << row << " , " << col << " : " <<  root->data << endl;
        if(m.find(col)==m.end()) m[col] = {row,root->data};
        else if(m[col].first<=row){
            m[col] = {row,root->data};
        }
        inorder(root->left, m, col-1, row+1);
        inorder(root->right, m, col+1, row+1);
        
    }
    vector<int> bottomView(Node *root) {
        // code here
        // traverse through all nodes add to map with col : node (override)
        // map returns in sorted order so -2 -1 0 1 2 3 cols whihc is bottom view of tree
        map<int,pair<int,int>> m;
        int col = 0;
        inorder(root, m, 0,0);
        
        vector<int> ans;
        for(auto it = m.begin(); it!=m.end(); it++){
            ans.push_back(it->second.second);
        }
        return ans;
    }
};