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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *first = head, *second = head;
            int cnt = n;
            while(cnt){
                first = first->next;
                cnt--;
            }
    
            if(first==NULL) {
                head = head->next;
                return head;
            }
    
            while(first->next != NULL){
                first = first->next;
                second = second->next;
            }
    
            second->next = second->next->next;
    
            return head;
        }
        ListNode* removeNthFromEnd1(ListNode* head, int n) {
            int length=0;
            ListNode *temp = head;
            while(temp){
                length++;
                temp = temp->next;
            }
            n = length-n;
    
            if(n==0) {
                head = head->next;
                return head;
            }
            temp = head;
            while(n>1){
                temp = temp->next;
                n--;
            }
            temp->next = temp->next->next;
            return head;
        }
    };