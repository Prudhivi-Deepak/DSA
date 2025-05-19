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
        ListNode* deleteMiddle(ListNode* head) {
            ListNode *first = head->next, *second = head;
    
            if(first == NULL) {
                head = head->next;
                return head;
            }
    
            while(first->next && first->next->next){
                first = first->next->next;
                second = second->next;
            }
            second->next = second->next->next;
            return head;
        }
    };