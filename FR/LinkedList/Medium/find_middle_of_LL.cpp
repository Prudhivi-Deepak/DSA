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
    ListNode* middleOfLinkedList(ListNode* head) {

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;

        // odd nodes 
        // example
        //     1 2 3 4 5
        //             f
        //         s
        // even nodes
        // example
        //     1 2 3 4 5 6
        //                 f
        //           s
        // so if f->next is null or f is null then we return the s done
    }
};