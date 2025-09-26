#include <bits/stdc++.h>
using namespace std;

void findPSE(vector<int> arr, int  n, vector<int> &pse){
        int i = 0;
        stack<int> st;

        while(i<n){
            while(!st.empty() && arr[st.top()] <= arr[i] ){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;
        }

    }
    vector <int> stockSpan(vector<int> arr, int n) {

        // rewrite the question it means get all ele <= curr ele count 
        // <= this condition breaks when we get a greater element whihc is previous greater ele for curr ele
        //  2(pse) . . . 6(i) = 4 element <= 6 index = i-pse = 6-2 = 4


        int i=1;
        vector<int> span(n, -1);
        findPSE(arr, n, span);

        for(int i=0; i<n; i++){
            span[i] = i-span[i];
        }       
        
        return span;
    }