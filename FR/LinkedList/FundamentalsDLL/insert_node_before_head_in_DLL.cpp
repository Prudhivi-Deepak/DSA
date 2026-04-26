/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        // Your code goes here
        ListNode *currNode = new ListNode(X);

        // ListNode *temp = head;

        // if(head->data == X){
        currNode->next = head;
        head->prev = currNode;
        head = currNode;
        return head;
        // }

        // while(temp && temp->next && temp->next->data == X){
        //     temp = currNode->next;
        // }

        // if(temp == nullptr || temp->next == nullptr) return head;
        // if(temp && temp->next && temp->next->data == X) return head;

        // currNode->next = temp->next;
        // currNode->prev = temp;
        // currNode->next->prev = currNode;
        // currNode->prev->next = currNode;
        // return head;
    }
};