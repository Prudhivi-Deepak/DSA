struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        ListNode* reverseLL(ListNode *head){
            ListNode *last = head;
            ListNode *curr = last->next;
            last->next = NULL;
            ListNode *future = curr->next;
            while(future){
                curr->next = last;
                last = curr;
                curr = future;
                future = future->next;
            }
            curr->next = last;
            last = curr;
            curr = future;
    
            return last;
    
        }
    
        ListNode * getKthNode(ListNode *head, int k){
            int count = 1;
            while(head && count<k){
                head = head->next;count++;
            }
            return head;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head->next == NULL || k==1) return head;
    
            int cnt = 1;
            ListNode *temp = head, *prevtail = NULL;
    
            while(temp){
                ListNode *kthnode = getKthNode(temp,k);
    
                if(kthnode == NULL){
                    if(prevtail) prevtail->next = temp;
                    return head;
                }
    
                ListNode *nextNode = kthnode->next;
                kthnode->next = NULL;
                ListNode *newhead = reverseLL(temp);
    
                if(temp == head) head = newhead;
                else prevtail->next = newhead;
    
                temp->next = nextNode;
                prevtail = temp;
                temp = nextNode;
    
            }
    
            return head; 
        }
    };