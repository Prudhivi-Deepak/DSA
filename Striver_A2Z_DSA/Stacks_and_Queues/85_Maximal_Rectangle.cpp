#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int LargestRectangle(vector<int> heights){
            stack<int> st;
            int area = 0, i=0, n = heights.size();
    
            while(i<n){
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
        int maximalRectangle(vector<vector<char>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> heights(m, 0);
            int maxArea = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(matrix[i][j]=='1') heights[j] = heights[j]+1;
                    else heights[j] = 0;
                }
                maxArea = max(maxArea, LargestRectangle(heights));
            }
            return maxArea;
        }
    };