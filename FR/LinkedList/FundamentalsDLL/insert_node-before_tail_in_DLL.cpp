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
    ListNode* insertBeforeTail(ListNode* head, int X) {
        // Your code goes here

        ListNode *currNode = new ListNode(X);
        ListNode *temp = head;

        if(temp->next==nullptr){
            currNode->next = head;
            head->prev = currNode;
            return currNode;
        }

        while(temp->next->next){
            temp = temp->next;
        }

        currNode->next = temp->next;
        currNode->prev = temp;
        currNode->next->prev = currNode;
        currNode->prev->next = currNode;

        return head;

    }
};
