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
        ListNode* reverseList(ListNode* head) {
            if(head==NULL || head->next==NULL) return head;
    
            ListNode* last = NULL;
            ListNode* curr = head;
            ListNode* future = head->next;
    
            while(future!=NULL){
                curr->next = last;
                last = curr;
                curr = future;
                future = future->next;
            }
            curr->next = last;
            head = curr;
            return head;
        }
    };