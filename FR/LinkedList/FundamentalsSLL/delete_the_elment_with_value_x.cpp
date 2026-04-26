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
        ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
            //your code goes here

            ListNode *temp = head;
            if(head->data == X){
                head = head->next;
                delete temp;
                return head;
            }

            while(temp && temp->next && temp->next->data != X){
                temp = temp->next;
            }

            if(temp && temp->next && temp->next->data == X){
                ListNode *freeNode = temp->next;
                temp->next = temp->next->next;
                delete freeNode;
            }

            return head;
        }
};