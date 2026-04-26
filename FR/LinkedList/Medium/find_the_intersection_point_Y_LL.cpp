/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // l1 l2 --> iterate 
        // after l1 complete assign to l2 headA
        // after l2 completes assign to l1 headB

        // Now if they meet at some point then it is the merging point
        // else reutnr NULL

        ListNode *l1 = headA, *l2 = headB;

        while(l1 && l2){
            if(l1==l2) return l1;
            l1 = l1->next;
            l2 = l2->next;
            if(l1==nullptr && l2==nullptr) return nullptr;
            if(l1 == nullptr) l1 = headB;
            if(l2 == nullptr) l2 = headA;
        }
        return nullptr;
    }
};