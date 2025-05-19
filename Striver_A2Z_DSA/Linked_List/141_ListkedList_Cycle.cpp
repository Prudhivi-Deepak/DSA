
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
        bool hasCycle(ListNode *head) {
            if(head ==NULL || head->next==NULL || head->next->next == NULL) return false;
            ListNode* slow = head->next;
            ListNode* fast = head->next->next;
            
            while(slow != fast){
                if(slow->next == NULL || fast->next == NULL || fast->next->next == NULL) return false;
                slow = slow->next;
                fast = fast->next->next;
            }
    
            return true;
        }
    };