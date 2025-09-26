#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // 3 5 1 7 5 9

        // i am at index i find pse and nse, so we can tell what is the max area 
        // formula is (width)(nse-pse-1)*(height) height[i];

        stack<int> st;
        // if curr element is < stack top curr is nse of stack's top and its prev one is pse

        int i = 0, n = heights.size(), maxArea = 0;

        while(i<n){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                int nse = i;
                int top = heights[st.top()]; st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse-pse-1)*top);
            }

            st.push(i);
            i++;
        }

         while(!st.empty()){
            int nse = n;
            int top = heights[st.top()]; st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1)*top);
        }
        return maxArea;
    }

    int largestRectangleAreaFirstTry(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int i=0, area = 0;
        while(i<n){
            // nse - if curr value is < top then it is nse for top and its pse will be next top
            // area = (nse - pse -1)*heights[i]
            while(!st.empty() && heights[i] < heights[st.top()]){
                int value = heights[st.top()];st.pop();
                int value_pse = st.empty() ? -1 : st.top();
                area = max(area, (i-value_pse-1)*value);
            }

            st.push(i);
            i++;
        }

        while(!st.empty()){
            int value = heights[st.top()];st.pop();
            int value_pse = st.empty() ? -1 : st.top();
            area = max(area, (n-value_pse-1)*value);
        }
        return area;
    }

    int largestRectangleAreaBF(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> nseI(n, n), pseI(n, -1);

        int i=n-1;
        while(i>=0){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) nseI[i] = st.top();
            st.push(i);
            i--;
        }

        st = stack<int>();
        i=0;
        while(i<n){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) pseI[i] = st.top();
            st.push(i);
            i++;
        }

        int area = 0;
        for(i=0; i<n; i++){
            area = max(area, (nseI[i]-pseI[i]-1)*heights[i]);
        }
        return area;
    }
};