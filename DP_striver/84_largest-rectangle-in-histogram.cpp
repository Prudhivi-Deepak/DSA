#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN, maxi = INT_MIN, n = heights.size();
        stack<int> st;
        // st.push(0);
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
};