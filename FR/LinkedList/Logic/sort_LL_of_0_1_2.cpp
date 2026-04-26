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
        ListNode* sortList(ListNode* &head) {
            //your code goes here

            ListNode *zero = new ListNode(-1);
            ListNode *ones = new ListNode(-1);
            ListNode *twos = new ListNode(-1);

            ListNode *zeroHead = zero, *onesHead = ones, *twosHead = twos;

            ListNode *temp = head;

            while(temp){

                if(temp->data == 0){
                    zero->next = temp;
                    zero = temp;
                }
                else if(temp->data == 1){
                    ones->next = temp;
                    ones = temp;
                }
                else{
                    twos->next = temp;
                    twos = temp;
                }

                temp = temp->next;
                ones->next = twos->next = zero->next = nullptr;
            }

            // zeroHead ----..........--> zero-->nullptr
            // oneHead ----..........--> ones-->nullptr
            // twosHead ----..........--> twos-->nullptr

            if(zeroHead->next == nullptr){
                if(onesHead->next == nullptr){
                    return twosHead->next;
                }
                else{
                    ones->next = twosHead->next;
                    return onesHead->next;
                }
            }
            else{
                if(onesHead->next == nullptr){
                    zero->next = twosHead->next;
                    return zeroHead->next;
                }
                else{
                    ones->next = twosHead->next;
                    zero->next = onesHead->next;
                    return zeroHead->next;
                }
            }

            return nullptr;

            // 0 1 2 0 1 0 0 2 1 0 2 0 2 0 0 2 0 2 1 0 1 0

            // if it's array we do use left middle and right pointer
            // but here we can use that instead simply we can use 3 pointers and attach to them (change links)

            


        }
};