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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *first = headA, *second = headB;
    
            if(first == second) return headA;
    
            while(first!=second){
                first = first->next;
                second = second->next;
    
                if(first==NULL && second == NULL) return NULL;
    
                if(first == second) return first;
    
                if(first == NULL) first = headB;
                if(second == NULL) second = headA;
            }
    
            return first;
        }
    };