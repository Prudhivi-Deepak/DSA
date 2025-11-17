#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    Node * solve(int &i, int &j, vector<int> &pre, vector<int> &post){
        if(j>=1){
            cout << " i : " << i << " pre[i] : " << pre[i] << endl;
            cout << " j : " << j << " post[j] : " << post[j] << endl;
        }
        Node * currNode = new Node(pre[i++]);
        
        // no child because pre == post left most node
        if(currNode->data != post[j]){
            
            currNode->left = solve(i, j, pre, post);
            currNode->right= solve(i, j, pre, post);
        }
        
        j++;
        return currNode;
        
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        
        //0 1 2 3 4 5 6 7 8
        //1 2 4 8 9 5 3 6 7
        //8 9 4 5 2 6 7 3 1
        int i = 0, j = 0;
        return solve(i, j, pre, post);
    }
};