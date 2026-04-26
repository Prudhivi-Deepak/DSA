/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

struct compare {
    // row, value
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first == p2.first){
            // swap if true -> we need smaller value
            return p1.second > p2.second;
        }
        // sort based on row first
        return p1.first > p2.first;
    }
};

class Solution {
public:
    // map<int,vector<pair<int, int>>> umap;
    // void inorder(TreeNode *root, int row, int col){

    //     if(root==nullptr) return;

    //     inorder(root->left, row+1, col-1);

    //     if(umap.find(col)==umap.end()){
    //         umap[col] = {row, root->data};
    //     }
    //     else{
    //         umap[col].push_back({row, root->data});
    //     }

    //     inorder(root->right, row+1, col+1);
    // }

    void inorder(TreeNode *root, int row, int col, map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, compare>> &min_heap_map){

        if(root == nullptr) return;

        inorder(root->left, row+1, col-1, min_heap_map);

        if(min_heap_map.find(col)==min_heap_map.end()){
            priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
            pq.push({row, root->data});
            min_heap_map[col] = pq;
        }
        else{
            min_heap_map[col].push({row, root->data});
        }

        inorder(root->right, row+1, col+1, min_heap_map);
    }




    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	//your code goes here

        map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, compare>> min_heap_map;

        inorder(root, 0, 0, min_heap_map);

        vector<vector<int>> ans;

        for(auto it=min_heap_map.begin(); it!=min_heap_map.end(); it++){
            auto eachColpq = it->second;
            vector<int> eachLevel;

            while(!eachColpq.empty()){
                auto [row, value] = eachColpq.top(); eachColpq.pop();
                eachLevel.push_back(value);
            }
            ans.push_back(eachLevel);
        }

        return ans;

        // inorder(root, 0);
        // vector<vector<int>> ans;
        // for(auto it=umap.begin(); it!=umap.end(); it++){
        //     // cout << it->first << endl;
            
        //     ans.push_back(it->second);
        // }
        // return ans;       

    }
};