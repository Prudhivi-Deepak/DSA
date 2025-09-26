#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
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