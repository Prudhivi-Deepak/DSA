/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int val1)
    {
        val = val1;
        next = NULL;
    }
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode * findMiddle(ListNode *startNode){
        ListNode *slow = startNode, *fast = startNode->next;

        if(fast == nullptr) return startNode;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow  = slow->next;
        }

        return slow;
    }

    ListNode *mergeLL(ListNode *ll1, ListNode *ll2){

        ListNode *newHead = new ListNode(-1), *returnHead = newHead;

        while(ll1 || ll2){
            if(ll1 && ll2){
                if(ll1->val <= ll2->val){
                    newHead->next = ll1;
                    newHead = ll1;
                    ll1 = ll1->next;
                }
                else{
                    newHead->next = ll2;
                    newHead = ll2;
                    ll2 = ll2->next;
                }
            }
            else if(ll1){
                newHead->next = ll1;
                break;
            }
            else{
                newHead->next = ll2;
                break;
            }
            newHead->next = nullptr;
        }
        return returnHead->next;
    }

    ListNode *DivideLL(ListNode *startNode){

        if(startNode == nullptr || startNode->next == nullptr) return startNode;

        ListNode *middleNode = findMiddle(startNode);

        ListNode *secondHalf = middleNode->next;
        middleNode->next = nullptr;

        startNode = DivideLL(startNode);
        secondHalf = DivideLL(secondHalf);

        return mergeLL(startNode, secondHalf);
    }

    ListNode* sortList(ListNode* head) {

        return DivideLL(head);
        
        // head -> 5 -> 6 -> 1 -> 2 -> 1 -> nullptr
        //                        f
        //              s

        // head -> 5 -> 6 -> 1 -> 2 -> nullptr
        //                        f
        //              s






        // find the middle element 


        // divide(head, untill s)
        // divide(from s->next, end)
        // now mergetheboth array(head, middle, end)




        

    }
};

