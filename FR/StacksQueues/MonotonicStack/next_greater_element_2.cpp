class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> NGE(n, -1);

        for(int i=2*n-1; i>=0; i--){
            int index = i%n;

            while(!st.empty() && st.top()<=arr[index]) st.pop();
            NGE[index] = st.empty() ? -1 : st.top();
            st.push(arr[index]);
        }
        return NGE;
    }
};