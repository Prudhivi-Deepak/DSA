#include <bits/stdc++.h>
using namespace std;


class ArrayQueue {
    public:
        int q[1000];
        int front = -1, last = -1;
        ArrayQueue() {
        }
        
        void push(int x) {
            if(front==-1 && last==-1){
                front++;last++;
            }
            else{
                last++;
            }
            q[last] =x;
        }
        
        int pop() {
            return q[front++];
        }
        
        int peek() {
            return q[front];
        }
        
        bool isEmpty() {
            if(front== -1 && last == -1) return true;
            if(front>last) return true;
            return false;
        }
    };