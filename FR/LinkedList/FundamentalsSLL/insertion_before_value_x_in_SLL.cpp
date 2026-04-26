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
        ListNode* insertBeforeX(ListNode* &head, int X, int val) {
            //your code goes here
            ListNode *newNode = new ListNode(val);
            if(head->data == X){
                newNode -> next  = head;
                head = newNode;
                return head;
            }

            ListNode *temp = head;
            while(temp->next && temp->next->data != X){
                temp = temp->next;
            }

            if(temp->next == nullptr) return head;
            if(temp && temp->next && temp->next->data != X) return head;

            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
};