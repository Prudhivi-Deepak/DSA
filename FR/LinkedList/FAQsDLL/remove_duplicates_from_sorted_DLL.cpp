/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {

        // 1 3 4 5 6 7 8 9
        // 1 2
        // p c n 

        ListNode *prevNode = head, *curr = head->next, *nextNode = (curr  ? curr->next : nullptr);

        while(curr){
            if(curr->val == prevNode->val){

                // delete curr
                prevNode->next = curr->next;
                if(curr->next) curr->next->prev = prevNode;

                ListNode *freeNode = curr; delete freeNode;

            }
            else{
                prevNode = curr;
            }
            curr = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        return head;
    }
};