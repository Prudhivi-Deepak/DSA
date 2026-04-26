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
        ListNode* deleteKthNode(ListNode* &head, int k) {
            // Your code goes here
            // .-> nullptr
            // .->.->nullptr cnt = 1, cnt < k-1 
            // .->.->.->nullptr

            int cnt = 1;
            ListNode *temp = head;

            if(k==1){
                head = head->next;
                delete temp;
                return head;               
            }

            while(cnt < k-1){
                temp = temp->next; cnt++;
            }
            
            ListNode *freeNode = temp->next;
            temp->next = temp->next->next;
            delete freeNode;
            return head;

        }
};
