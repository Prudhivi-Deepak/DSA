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
		void AllTraversal(TreeNode *root, vector<vector<int>> &AllOrders){
			// 0 - in order, 1 - pre order, 2 - post order
			if(root == nullptr) return;

			// pre order
			AllOrders[1].push_back(root->data);
			AllTraversal(root->left, AllOrders);
			// inorder
			AllOrders[0].push_back(root->data);
			AllTraversal(root->right, AllOrders);
			// post order
			AllOrders[2].push_back(root->data);
		}

		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
			// inord, preord, postord
			vector<vector<int>> AllOrders(3);

			// AllTraversal(root, AllOrders);
			// return AllOrders;

			stack<pair<TreeNode *,int>> st;
			st.push({root, 0});

			while(!st.empty()){
				auto [currNode, state] = st.top(); st.pop();
				// cout << currNode->data << " : " << state << endl;
				if(state == 0){ // first time we see this node
					AllOrders[1].push_back(currNode->data);
					st.push({currNode, state+1});
					if(currNode->left) st.push({currNode->left, 0});
				}
				else if(state == 1){ //second time we see thsi node
					AllOrders[0].push_back(currNode->data);
					st.push({currNode, state+1});
					if(currNode->right) st.push({currNode->right, 0});
				}
				else{
					AllOrders[state].push_back(currNode->data);
				}
			}

			return AllOrders;
		}
};