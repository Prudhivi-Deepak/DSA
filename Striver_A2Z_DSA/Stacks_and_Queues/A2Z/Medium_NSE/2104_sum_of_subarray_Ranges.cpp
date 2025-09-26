#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNseI(vector<int> &arr, vector<int> &nseI) {
        stack<int> st;
        int n = arr.size(), i = n - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nseI[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;
        }
    }

    void findNLeI(vector<int> &arr, vector<int> &nseI) {
        stack<int> st;
        int n = arr.size(), i = n - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            nseI[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;
        }
    }

    void findPseI(vector<int> &arr, vector<int> &pseI) {
        stack<int> st;
        int n = arr.size(), i = 0;
        while (i < n) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pseI[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }
    }

    void findPLeI(vector<int> &arr, vector<int> &pseI) {
        stack<int> st;
        int n = arr.size(), i = 0;
        while (i < n) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            pseI[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }
    }

    long long subArrayRanges(vector<int> &arr) {
        // return the sum of mins in all subarrays

        // 3 1 2 5
        int n = arr.size();
        vector<int> NseI(n, n), PseI(n, -1), NLeI(n, n), PLeI(n, -1);
        findNseI(arr, NseI);
        findNLeI(arr, NLeI);
        findPseI(arr, PseI);
        findPLeI(arr, PLeI);

        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            int nextSE = NseI[i] - i;
            int PrevSE = i - PseI[i];

            long long freq = nextSE * PrevSE * 1LL;
            sum1 = sum1 + freq * arr[i] * 1LL;

            int nextLE = NLeI[i]-i;
            int PrevLE = i - PLeI[i];

            long long freqL = nextLE * PrevLE * 1LL;
            sum2 = sum2 + freqL * arr[i] * 1LL ;
        }
        return sum2-sum1;
    }

    long long subArrayRangesFirstTry(vector<int>& nums) {
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