class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> NGE(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            NGE[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return NGE;
    }
};
