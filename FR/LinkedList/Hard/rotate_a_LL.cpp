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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;

        int length = 1;
        ListNode *temp = head;
        while(temp->next){
            temp = temp->next; length++;
        }
        cout << length << endl;
        temp->next = head;

        k = length - k%length;
        temp = head;
        while(k>1){
            temp = temp->next; k--;
        }
        head = temp->next;
        temp->next= nullptr;

        return head;

    }
};