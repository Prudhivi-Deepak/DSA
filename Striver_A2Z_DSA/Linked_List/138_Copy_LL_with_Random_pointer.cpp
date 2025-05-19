struct Node {
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : val(x), next(next), random(random) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        Node* copyRandomList(Node* head) {
    
            if(head==NULL) return head;
    
            Node *temp = head;
            while(temp){
                Node *newNode = new Node(temp->val);
                newNode ->next = temp->next;
                temp->next = newNode;
                temp = temp->next->next;
            }
    
            temp = head;
    
            while(temp){
                if(temp->random == NULL){
                    temp->next->random = NULL;
                }
                else{
                    temp->next->random = temp->random->next;
                }
                temp = temp->next->next;
            }
    
            temp = head;
            Node *newhead = temp->next;
            Node *returnPointer = newhead;
    
            while(temp->next && temp->next->next){
                temp->next = temp->next->next;
                newhead->next = temp->next->next;
    
                temp = temp->next;
                newhead = newhead->next;
            }
            if(temp) temp->next = NULL;
    
            return returnPointer;
        }
    };