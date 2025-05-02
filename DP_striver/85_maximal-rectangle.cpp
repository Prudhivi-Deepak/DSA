#include<bits/stdc++.h>
using namespace std;
class Solution {

int largestRectangleArea(vector<int>& heights) {
    int maxArea = INT_MIN, maxi = INT_MIN, n = heights.size();
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && heights[i] < heights[st.top()]){

            int value_ind = st.top(); st.pop();
            int pse = st.empty()? -1: st.top();
            int nse = i;

            maxi = max(maxi, heights[value_ind]*(nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()){
        int value_ind = st.top(); st.pop();
        int pse = st.empty()? -1: st.top();
        int nse = n;
        maxi = max(maxi, heights[value_ind]*(nse-pse-1));
    }
    return maxi;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        int maxi = INT_MIN;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                    if(matrix[i][j] == '1') heights[j]++;
                    else heights[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};