#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution {
public:
    int mod = 1e9+7;

    void findNseI(vector<int> &arr, vector<int> &nseI){
        stack<int> st;
        int n = arr.size(), i=n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }

            nseI[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;
        }
    }

    void findPseI(vector<int> &arr, vector<int> &pseI){
        stack<int> st;
        int n = arr.size(), i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()] > arr[i] ){
                st.pop();
            }

            pseI[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }
    }

    int sumSubarrayMins(vector<int> &arr) {
        // return the sum of mins in all subarrays

        // 3 1 2 5
        int n = arr.size();
        vector<int> NseI(n, n), PseI(n, -1);
        findNseI(arr, NseI);
        findPseI(arr, PseI);

        long long sum = 0;
        for(int i=0; i<n; i++){
            int nextSE = NseI[i]-i;
            int PrevSE = i-PseI[i];
            long long freq = nextSE*PrevSE*1LL % mod;
            sum = (sum + freq*arr[i]*1LL%mod)%mod;
        }
        return sum;
    }
    int sumSubarrayMinsFirstTry(vector<int>& arr) {
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