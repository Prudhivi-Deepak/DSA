#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int x){
        val = x;
        next = nullptr;
    }
};

class LinkedListQueue {
public:
    Node *front, *last;
    LinkedListQueue() {
        // last -> 5<-6<-7 <- front;
        // push 9
        // last -> 9<-5<-6<-7 <- front;
        // pop
        // last -> 9<-5<-6 <- front;
        // 

        front = last = nullptr;
    }
    
    void push(int x) {
        Node *newNode = new Node(x);
        if(front==nullptr && last==nullptr){
            front = last = newNode;
        }
        else{
            last->next = newNode;
            last = newNode;
        }
    }
    
    int pop() {
        int f = front->val;
        if(front!= nullptr && front==last){
            front = last = nullptr;
            return f;
        }

        front = front->next;
        return f;
    }
    
    int peek() {
        return front->val;
    }
    
    bool isEmpty() {
        return (front==nullptr);
    }
};