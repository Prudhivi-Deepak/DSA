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

class Solution
{
public:
    ListNode *arrayToDoublyLinkedList(vector<int> &arr) {
        // Your code goes here
        ListNode *head = nullptr, *tail = nullptr;
        for(int i : arr){
            ListNode *currNode = new ListNode(i);

            if(head==nullptr){
                head = currNode;
                tail = currNode;
            }
            else{
                currNode->prev = tail; 
                tail->next =  currNode;
                tail = currNode;
            }
        }
        return head;
    }
};