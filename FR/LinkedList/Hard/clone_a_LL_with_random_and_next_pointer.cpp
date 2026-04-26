/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};
*/

class Solution {
public:
    ListNode* copyRandomList(ListNode* head) {

        // create duplicate nodes next to each node 
        // now iterate again with 2 pointers
        // old = old->next is old->next->next
        // new = new->next is new->next->next
        // new->random  = old->random->next;


        ListNode *temp = head;
        while(temp){
            ListNode *newNode = new ListNode(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        ListNode *old = head, *newNode = head->next;
        ListNode *newHead = newNode;
        while(old){
            if(old->random) old->next->random = old->random->next;
            old = old->next->next;
        }

        old = head;
        while(old){
            old->next = old->next->next;
            if(newNode->next) newNode->next = newNode->next->next;

           old = old->next;
           newNode = newNode->next;
        }
        
        return newHead;
    }
};