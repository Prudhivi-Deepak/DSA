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
    int findLengthOfLoop(ListNode *head) {

        ListNode *slow = head, *fast = head;
        if(head == nullptr || head->next == nullptr) return 0;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                // slow = head;
                int length = 1;
                slow = slow->next;
                while(fast != slow){
                    length++;
                    slow = slow->next;
                }
                return length;
            }
        }

        return  0;
    }
};