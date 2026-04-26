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
    ListNode *findStartingPoint(ListNode *head) {

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow = head;
                break;
            }
        }

        while(fast && slow && fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow) return fast;

        return nullptr;

    }
};