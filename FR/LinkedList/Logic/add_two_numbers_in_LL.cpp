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

        ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
            //your code goes here

            // if i add 2 number i get sum adn carry
            int carry = 0;

            ListNode *l1 = linkedList1, *l2 = linkedList2, *finalreturnPointer = l1, *lastNode = nullptr;
            
            while(l1 || l2){
                int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry; 
                    
                if(l1) l1->data = sum%10;
                if(l2) l2->data = sum%10;
                carry = sum/10;

                if(l1 && l2 && !l1->next && !l2->next && !lastNode) lastNode = l1;

                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;
                
                if(l1 && !l2){
                    lastNode = l1;
                    finalreturnPointer = linkedList1;
                }
                else if(!l1 && l2){
                    lastNode = l2;
                    finalreturnPointer = linkedList2;
                }
            }

            if(carry){
                ListNode *newnode = new ListNode(carry);
                lastNode->next = newnode;
            }

            return finalreturnPointer;
        }
};