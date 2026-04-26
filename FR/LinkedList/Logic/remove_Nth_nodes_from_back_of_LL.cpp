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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // now we have to remove nth node from last may be lets have 
        // 2 pointers back and front

        // front goes to n distance from head first
        // now we move back and front untill end of LL
        // so back will be at n distance from end of LL right
        // now i will remove the nth node (but to remove nth node i should be at n+1st node from last)
        // so front goes to n+1 node

        // example
        // 1 2 3 4 5 -> NULL n = 2
        //     b   f --> remove 4 now simple
        // n = n+1 = 3

        n = n+1;
        ListNode *front = head, *back = head;
        int cnt = 1;

        while(cnt < n){
            front = front->next; cnt++;
        }

        if(front == nullptr){
            // remove head;
            head = head->next;
            delete back;
            return head;
        }

        while(front->next){
            front = front->next;
            back = back->next;
        }

        // remove back->next
        ListNode *freeNode = back->next;
        back->next = back->next->next;
        return head;
    }
};