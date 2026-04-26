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
    ListNode* reverseList(ListNode* head) {

    //     example
        
    //     1 2 3 4 5 -> nullptr
    // p=n c n

    // c->next = p;

    // p = c;
    // c = n;
    // n = n->next;

        ListNode *prevNode = nullptr, *currNode = head, *nextNode = currNode->next;

        if(nextNode == nullptr) return head;

        while(currNode){
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        head = prevNode;
        return head;        
    }
};