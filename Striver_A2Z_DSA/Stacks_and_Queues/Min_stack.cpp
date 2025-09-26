#include <bits/stdc++.h>
using namespace std;

class MinStack {
    public:
        // stack<pair<int,int>> st;
        stack<long long> st;
        long long minele;
        MinStack() {
            st = {};
        }
        
        void push(int val) {
            if(st.empty()){
                st.push(val);
                minele = val;
            }
            else if(minele <= val){
                st.push(val);
            }
            else{
                long long newval = 2*(long long)val-minele;
                minele = val;
                st.push(newval);
            }
    
            // if(st.empty())
            //     st.push({val,val});
            // else if(val < st.top().second)
            //     st.push({val,val});            
            // else
            //     st.push({val,st.top().second});
        }
        
        void pop() {
            if(st.top()<minele){
                minele = 2*minele - st.top();
            }
            st.pop();
            // st.pop();
        }
        
        int top() {
    
            if(st.top()>minele){
                return st.top();
            }
            else{
                return minele;            
            }
        
            // return st.top().first;
        }
        
        int getMin() {
            return minele;
            // return st.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */