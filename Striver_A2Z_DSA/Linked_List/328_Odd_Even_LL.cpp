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
        ListNode* oddEvenList(ListNode* head) {
            if(head==NULL) return head;
            ListNode *odd_p = head, *even_head = head->next, *even_p = head->next;
            while(odd_p && even_p){
                if(odd_p->next && odd_p->next->next) odd_p->next = odd_p->next->next;
                else odd_p->next=NULL;
                if(even_p->next && even_p->next->next) even_p->next = even_p->next->next;
                else even_p->next = NULL;
    
                if(odd_p->next) odd_p=odd_p->next;
                even_p = even_p->next;
    
            }
            if(odd_p) odd_p->next = even_head;
            return head;
        }
        ListNode* oddEvenList1(ListNode* head) {
            vector<int> odd_L, even_L;
            ListNode* temp = head;
            while(temp){
                if(temp) odd_L.push_back(temp->val);
                temp = temp->next;
                if(temp) {
                    even_L.push_back(temp->val);
                    temp = temp->next;
                }
            }
    
            temp = head;
            int i=0; 
            while(temp){
                temp->val = odd_L[i++];
                temp = temp->next;
                if(i==odd_L.size()) break;
            }
            i=0;
            while(temp){
                temp->val = even_L[i++];
                temp = temp->next;
                if(i==even_L.size()) break;
            }
            return head;
        }
    };