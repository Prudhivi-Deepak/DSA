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
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
        // Your code goes here

        ListNode *newNode = new ListNode(X);
        ListNode *temp = head;
        int cnt = 2;

        if(K == 1){
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }

        while(cnt < K){
            temp = temp->next;cnt++;
        }

        if(temp == nullptr || temp->next == nullptr) return head;

        newNode->next = temp->next;
        if(newNode->next) newNode->next->prev = newNode;
        newNode->prev = temp;
        newNode->prev->next = newNode;

        return head;
    }
};