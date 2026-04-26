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
        ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
            //your code goes here
            int cnt = 2;
            ListNode *newNode = new ListNode(X);
            if(head == nullptr) return newNode;
            if(K == 1) {
                newNode->next = head;
                head = newNode;
                return head;
            }
            ListNode *temp = head;
            while(cnt < K){
                temp = temp->next; cnt++;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            return head;
            
        }
};