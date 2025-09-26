#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> nseI(n, n);
        vector<int> pseI(n, -1);

        int i=n-1;
        while(i>=0){
            if(!st.empty() && arr[st.top()] < arr[i]){
                nseI[i] = st.top();
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                if(!st.empty()) nseI[i] = st.top();
            }

            st.push(i);
            i--;
        }

        // st.clear();
        st = stack<int>();

        i = 0;
        while(i<n){
            if(!st.empty() && arr[st.top()] <= arr[i]){
                pseI[i] = st.top();
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }

                if(!st.empty()) pseI[i] = st.top();
            }

            st.push(i);
            i++;
        }

        long long total = 0LL;
        for(i=0; i<n; i++){
            total = (total%mod + (((long long)nseI[i]-i)*(i-pseI[i])*arr[i])%mod)%mod;
        }
        return total%mod;
    }
};