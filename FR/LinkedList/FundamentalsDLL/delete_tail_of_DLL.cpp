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
    ListNode *deleteTail(ListNode *&head) {
        // Your code goes here
        ListNode *tempNode = head;

        if(tempNode->next == nullptr){
            delete tempNode;
            return nullptr;
        }

        while(tempNode->next->next){
            tempNode = tempNode->next;
        }

        ListNode *freeNode = tempNode->next->next;
        tempNode -> next = nullptr;
        delete freeNode;
        return head;
    }
};