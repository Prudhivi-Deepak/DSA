#include <bits/stdc++.h>
using namespace std;

struct Node1{
    pair<int, int> data;
    Node1* next;
    Node1* prev;
};


struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

class LRUCache {
public:
    Node *root, *back;
    int capacity;
    unordered_map<int, Node*> Node_address;
    LRUCache(int capacity) { 
        this->capacity = capacity; 
        this->root = new Node(-1, -1);
        this->back = new Node(-1, -1);

        root->next = back;
        back->prev = root;
    }

    int get(int key_) {
        if(Node_address.find(key_)==Node_address.end()) return -1;

        // delete the node and insert at the root

        Node *currNode = Node_address[key_];
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;

        currNode->next = root->next;
        currNode->prev = root;
        root->next->prev = currNode;
        root->next = currNode;

        return currNode->value;        
    }

    void put(int key_, int value) {

        if(Node_address.find(key_)!=Node_address.end()){
            Node_address[key_]->value = value;

            Node *currNode = Node_address[key_];

            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;

            currNode->next = root->next;
            currNode->prev = root;
            root->next->prev = currNode;
            root->next = currNode;

            return;
        }

        if(capacity==0){
            Node *lastNode = back->prev;
            int lastNodeKey = lastNode->key;
            back->prev = lastNode->prev;
            lastNode->prev->next = back;
            Node_address.erase(lastNodeKey);
        }
        else capacity--;

        Node *newNode = new Node(key_, value);
        newNode->next = root->next;
        newNode->prev = root;
        root->next->prev = newNode;
        root->next = newNode;      

        Node_address[key_] = newNode;  
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */