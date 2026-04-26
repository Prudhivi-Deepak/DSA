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
    void insertBeforeGivenNode(ListNode* node, int X) {
        // Your code goes here

        ListNode *newNode = new ListNode(X);
        ListNode *temp = node->prev;

        newNode->next = temp->next;
        newNode->prev = temp;
        if(newNode->next) newNode->next->prev = newNode;
        newNode->prev->next = newNode;
    }
};
