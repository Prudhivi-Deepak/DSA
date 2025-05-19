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
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==NULL || head->next==NULL) return head;
    
            ListNode *temp = head;    
    
            int length = 1;
            while(temp->next){
                temp = temp->next;
                length++;
            }
            
            temp->next = head;
            k = length - k%length;
            temp = head;
            while(k>1){
                temp = temp->next;
                k--;
            }
            ListNode *newhead = temp->next;
            temp->next = NULL;
    
            return newhead;
        }
    };