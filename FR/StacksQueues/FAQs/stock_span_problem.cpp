class Solution
{
    public:
    void findPGEI(vector<int> &pgeI, vector<int> &arr ){
        stack<int> st;
        int n = arr.size();

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            pgeI[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    vector <int> stockSpan(vector<int> arr, int n) {
        vector<int> pgeI(n, -1);
        findPGEI(pgeI, arr);

        vector<int> ans(n, 1);
        
        for(int i=0; i<n; i++){
            // we know if pseI is 4 and currIndex is 6 (tha menas 5 6 is valid = 2 nums)
            // 6-4 = 2
            ans[i] = i-pgeI[i];
        }
        return ans;
    }
};
