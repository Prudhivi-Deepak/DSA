#include <bits/stdc++.h>
using namespace std;

class MinStack {
   public:
    stack<int> st;
    int mini;
    MinStack() {
    }

    void push(int value) {

        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else  if(value >= mini) {
            st.push(value);
        }
        else{
            int modified_value = 2*value-mini;
            st.push(modified_value);
            mini = value;
        }
    }

    void pop() {
        if(st.empty()) return;
        int top_value = st.top();st.pop();

        if(top_value < mini){
            mini = 2*mini - top_value;
        }
    }

    int top() {
        if(st.empty()) return -1;
        int top_value = st.top();

        if(mini < top_value) return top_value;
        return mini;

    }

    int getMin() {
        return mini;
    }
};