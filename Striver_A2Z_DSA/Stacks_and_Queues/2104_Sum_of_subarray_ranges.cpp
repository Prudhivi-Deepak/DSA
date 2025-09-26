#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            stack<int> st;
            int n = nums.size();
            vector<int> nseI(n, n), pseI(n, -1), ngeI(n, n), pgeI(n, -1);
    
            int i=n-1;
            //nse
            while(i>=0){
                while(!st.empty() &&  nums[st.top()] >= nums[i]){
                    st.pop();
                }
                if(!st.empty()) nseI[i] = st.top();
                st.push(i);
                i--;
            }
    
            st = stack<int>();
            i=0;
            //pseI
            while(i<n){
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }
                if(!st.empty()) pseI[i] = st.top();
                st.push(i);
                i++;
            }
    
            st = stack<int>();
            i=n-1;
            //ngeI
            while(i>=0){
                while(!st.empty() && nums[st.top()] <= nums[i]){
                    st.pop();
                }
                if(!st.empty()) ngeI[i] = st.top();
                st.push(i);
                i--;
            }
    
            st = stack<int>();
            i=0;
            //pgeI
            while(i<n){
                while(!st.empty() && nums[st.top()] < nums[i]){
                    st.pop();
                }
                if(!st.empty()) pgeI[i] = st.top();
    
                st.push(i);
                i++;
            }
    
            long long maxTotal=0;
            for(i=0; i<n; i++){
                maxTotal = maxTotal + (((long long)ngeI[i]-i)*(i-pgeI[i]) - ((long long)nseI[i]-i)*(i-pseI[i]))*nums[i];
            }
            return maxTotal;
        }
    };