/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIteratorLeft{
  public:
    stack<TreeNode *> st;
    BSTIteratorLeft(TreeNode *root){
        st.push(root);
        while(root->left){
            st.push(root->left);
            root = root->left;
        }
    }

    bool isNext(){
        return !st.empty();
    }

    int next(){
        auto topNode = st.top(); st.pop();

        if(topNode->right){
            TreeNode *temp = topNode->right;

            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        return topNode->data;
    }
};

class BSTIteratorRight{
  public:
    stack<TreeNode *> st;
    BSTIteratorRight(TreeNode *root){
        st.push(root);
        while(root->right){
            st.push(root->right);
            root = root->right;
        }
    }

    bool isNext(){
        return !st.empty();
    }

    int next(){
        auto topNode = st.top(); st.pop();

        if(topNode->left){
            TreeNode *temp = topNode->left;

            while(temp){
                st.push(temp);
                temp = temp->right;
            }
        }
        return topNode->data;
    }
};

class Solution{	
	public:
		bool twoSumBST(TreeNode* root, int k){
			//your code goes here

            BSTIteratorLeft LeftIter(root);
            BSTIteratorRight RightIter(root);

            int left = LeftIter.next();
            int right = RightIter.next();

            while(left < right){

                int sum = left + right;

                if(sum == k){
                    return true;
                }
                else if(sum > k){
                    right = RightIter.next();
                }
                else{
                    left = LeftIter.next();
                }
            }
            return false;            
		}
};