
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
        ListNode* middleNode(ListNode* head) {
            int length = 1;
            ListNode *temp = head;
            while(head!=NULL){
                head = head->next;
                length++;
            }
    
            if(length%2==0)
                length = length/2;
            else
                length = (length+1)/2;
            
            while(length>1){
                temp = temp->next;
                length--;
            }
            return temp;
        }
    };