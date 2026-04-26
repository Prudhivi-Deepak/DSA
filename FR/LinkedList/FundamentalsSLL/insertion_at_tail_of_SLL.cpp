/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* insertAtTail(ListNode* &head, int X) {
            //your code goes here
            ListNode *newNode = new ListNode(X);
            ListNode *temp = head;

            if(head == nullptr) return newNode;

            while(temp->next){
                temp = temp->next;
            }

            temp->next = newNode;
            
            return head;
        }
};