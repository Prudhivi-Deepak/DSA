/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator{
	public:
        stack<TreeNode *> st;
		BSTIterator(TreeNode* root){
			while(root){
                st.push(root);
                root = root->left;
            }
		}
		
		bool hasNext(){
            // cout << "hasNext call : " << st.top()->data << endl;
			return !st.empty();
		}
		
		int next(){
            auto topNode = st.top(); st.pop();

            if(topNode->right){
                // st.push(topNode->right);
                TreeNode *temp = topNode->right;

                while(temp){
                    st.push(temp);
                    temp = temp->left;
                }
            }
            return topNode->data;
		}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */two