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
        ListNode* deleteTail(ListNode* &head) {
            //your code goes here

            if(head->next == nullptr){
                delete head;
                return nullptr;
            }

            ListNode *temp = head;
            while(temp->next && temp->next->next){
                temp = temp->next;
            }
            ListNode *freetail = temp->next;
            if(freetail) delete freetail;
            temp->next = nullptr;
            return head;
        }
};