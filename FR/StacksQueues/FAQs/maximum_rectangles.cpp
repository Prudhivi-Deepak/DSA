class Solution
{
public:
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

    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0) heights[j] = 0;
                else heights[j] += 1;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};