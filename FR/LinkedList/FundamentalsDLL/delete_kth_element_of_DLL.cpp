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
    ListNode *deleteKthElement(ListNode *&head, int k) {
        // Your code goes here

        int cnt = 2;
        ListNode *temp = head;
        if(k == 1){
            head = head->next;
            if(head) head->prev = nullptr;
            delete temp;
            return head;
        }

        while(cnt < k){
            temp = temp->next; cnt++;
        }
        
        ListNode *freeNode = temp->next;
        temp->next = temp->next->next;
        if(temp->next) temp->next->prev = temp;
        delete freeNode;

        return head;

    }
};