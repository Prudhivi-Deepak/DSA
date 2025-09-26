#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    public:
        int st[1000];
        int tp = -1;
        ArrayStack() {
        }
        
        void push(int x) {
            tp++;
            st[tp] = x;
        }
        
        int pop() {
            return st[tp--];
        }
        
        int top() {
            return st[tp];
        }
        
        bool isEmpty() {
            if(tp==-1) return true;
            return false;
        }
    };