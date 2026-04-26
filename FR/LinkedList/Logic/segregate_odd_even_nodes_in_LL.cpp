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
        ListNode* oddEvenList(ListNode* &head) {
            //your code goes here

            // 1 2 3 4 5
            // 1->3->5 -> 2->4

            // 1 2 3 4 5
            // 1 2 3 4 5
                    // t

            // even(-1) -> 2(even) -> 4(even)

            // odd(-1) -> 1(odd) -> 3(odd) -> 5(odd)

            ListNode *even = new ListNode(-1);
            ListNode *odd = new ListNode(-1);
            
            ListNode *evenHead = even, *oddHead = odd;
            int index = 1;

            ListNode *temp = head;

            while(temp){

                if(index%2){
                    odd->next = temp;
                    odd = temp;
                }
                else{
                    even->next = temp;
                    even = temp;
                }
                temp = temp->next;
                odd->next = even->next = nullptr;
                index++;
            }

            if(oddHead->next){
                odd->next = evenHead->next;
                return oddHead->next;
            }

            return evenHead->next;
        }
};