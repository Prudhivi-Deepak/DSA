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


class LinkedListStack {
public:
    Node *rtop;
    LinkedListStack() {
        // rtop->5->6->7->8->null
        // push 9
        // rtop->9->5->6->7->8->null
        // push 10
        // rtop->10->9->5->6->7->8->null
        //
        rtop = nullptr;
    }
    
    void push(int x) {
        Node *newNode = new Node(x);
        newNode->next = rtop;
        rtop = newNode;
    }
    
    int pop() {
        // if(rtop==nullptr) return nullptr;
        int t = rtop->val;
        rtop = rtop->next;
        return t;
    }
    
    int top() {
        return rtop->val;
    }
    
    bool isEmpty() {
        return rtop==nullptr;
    }
};