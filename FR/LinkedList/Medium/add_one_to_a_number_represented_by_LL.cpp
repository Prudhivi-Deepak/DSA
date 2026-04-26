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
    ListNode(int val1)
    {
        val = val1;
        next = NULL;
    }
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
};
*/

class Solution {
public:

    int add(ListNode *currNode){
        if(currNode->next==nullptr){
            int sum = currNode->val + 1;
            currNode->val = sum%10;
            int carry = sum/10;
            return carry;
        }

        int backTrackCarry = add(currNode->next);
        int currSum = currNode->val + backTrackCarry;
        currNode->val = currSum%10;
        return currSum/10;
    }

    ListNode *addOne(ListNode *head) {

        // we have to reach to the last node and then add 1 to it then 
        // if carry is there return to backtrack back to front nodes
        // even after 1st node we have carry then create new node and make it head
        int carry = add(head);
        if(carry){
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;

       }
};