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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode *lastVal = NULL;
            ListNode *returnPointer_l1 = l1, *returnPointer_l2 = l2, *finalreturnPointer = NULL;
            // cout << "l1 : " << l1->val << " l2 : " << l2->val << endl;
            while(l1 || l2){
                int currvalue = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                // cout << "curr value : " << currvalue << endl;
                carry = currvalue/10;
                if(l1) l1->val = currvalue%10;
                if(l2) l2->val = currvalue%10;
    
                if(l1 && l2 && !l1->next && !l2->next && !lastVal) lastVal = l1;
    
                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;
    
                if(l1 && !l2) {
                    lastVal = l1;
                    finalreturnPointer = returnPointer_l1;
                }
                if(l2 && !l1) {
                    lastVal = l2;
                    finalreturnPointer = returnPointer_l2;
                }
            }
            
            if(carry){
                ListNode *newNode = new ListNode(carry);
                lastVal->next = newNode;
            }
            return finalreturnPointer ? finalreturnPointer : returnPointer_l1 ;
        }
    };