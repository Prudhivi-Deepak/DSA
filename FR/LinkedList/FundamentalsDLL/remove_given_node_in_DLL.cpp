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
    void deleteGivenNode(ListNode *node) {
        // Your code goes here

        if(node->next && node->prev){
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
        }
        else if(node->next){
            node->next->prev = nullptr;
            delete node;
        }
        else{
            node->prev->next = nullptr;
            delete node;
        }
    }
};