#include <bits/stdc++.h>
using namespace std;

struct Node{
    pair<int, int> data;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    //Least recently used (LRU nodes will be deleted when it == capacity and want to insert another element)
    int capacity, currcapacity = 0;
    map<int, Node*> keyNode; //map from ele key to node;

    Node *head = new Node();
    Node *tail = new Node();

    LRUCache(int capacity) {
        this->capacity = capacity;

        head->data = {-1,-1};
        tail->data = {-1,-1};

        head->next = tail;
        head->prev = nullptr;

        tail->prev = head;
        tail->next = nullptr;

        currcapacity = 0;
    }

    void printLL(Node *h){
        cout << "{" ;
        while(h!=nullptr){
            cout << h->data.first << "=" << h->data.second << ", ";
            h = h->next;
        }
        cout << "nullptr }" << endl;
    }
    
    int get(int key) {
        // cout << "get key : [" << key << "] ";
        if(keyNode.find(key)!=keyNode.end()){
            Node * tempNode = keyNode[key];

            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;

            tempNode->prev = head;
            tempNode->next = head->next;

            head->next = tempNode;
            tempNode->next->prev = tempNode;
            
            // cout << "return : " << keyNode[key]->data.second << endl;

            // printLL(head);

            return keyNode[key]->data.second;
        }
        else {
            // cout << "return : " << -1 << endl;
            return -1;
        }
    }
    // cpacity = 3;
    //<--h <--> t -->
    //<--h <--> Node(Key1) <---> t -->
    // <--h <--> Node(Key1) <----> Node(Key2) <---> t --> 
    // insert 3
    // <--h <--> Node(Key2) <----> Node(Key3) <---> t -->
    void put(int key, int value) {
        // cout << "put [" << key << ":" << value << "] ";

        if(keyNode.find(key)!=keyNode.end()){
            keyNode[key]->data.second = value;
            get(key);
        }
        else{
            Node *newNode = new Node();
            newNode->data = {key, value};

            if(currcapacity == capacity){
                //freq data comes first so reduce tail
                keyNode.erase(tail->prev->data.first);
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
                currcapacity--;
            }

            newNode->prev = head;
            newNode->next = head->next;

            head->next = newNode;
            newNode->next->prev = newNode;
            keyNode.insert({key, newNode});
            currcapacity++;
            // printLL(head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */