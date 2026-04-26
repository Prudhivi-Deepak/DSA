class Solution{
public:
    void findPSEI(vector<int> &pseI, vector<int> &heights){
        stack<int> st;
        int n = heights.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
            pseI[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNSEI(vector<int> &nseI, vector<int> &heights){
        stack<int> st;
        int n = heights.size();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nseI[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea1(vector<int> &heights) {
        int n = heights.size();
        vector<int> pseI(n, -1), nseI(n, n);

        findPSEI(pseI, heights);
        findNSEI(nseI, heights);

        // width is pse+1 to nse-1 == (nse-1) - (pse+1) + 1 = nse-1 - pse -1 +1 = nse-pse-1
        int maxArea = 0;
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, (nseI[i]-pseI[i]-1)*heights[i]);
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        int n = heights.size(), maxArea = 0;

        for(int i=0; i<n; i++){
            
            while(!st.empty() && heights[st.top()] >= heights[i] ){
                // top value >= currvalue means nse of top value is currvalue
                int nse = i;
                int currValue = heights[st.top()]; st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse-pse-1)*currValue);
            }
            st.push(i);
        }

        while(!st.empty()){
            // top value > currvalue means nse of top value is currvalue
            int nse = n;
            int currValue = heights[st.top()]; st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1)*currValue);
        }

        return maxArea;
    }
};