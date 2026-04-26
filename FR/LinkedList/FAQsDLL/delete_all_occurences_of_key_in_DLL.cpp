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
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

        while(head && head->val == target){
            // delete head;
            ListNode *freeNode = head;
            head = head->next;
            if(head) head->prev = nullptr;
            delete freeNode;
        }

        if(head == nullptr) return head;

        ListNode *curr = head->next, *nextNode = (head->next ? head->next->next : nullptr);
        while(curr){
            if(curr->val == target){
                ListNode *freeNode = curr;

                curr->prev->next = curr->next;
                if(curr->next) curr->next->prev = curr->prev;
                delete freeNode;
            }
            curr = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        
        return head;
    }
};