/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode *mergedTwoLL(ListNode *list1, ListNode *list2){

        ListNode *l1 = list1, *l2 = list2;

        ListNode *newHead = new ListNode(-1),  *returnHead = newHead;

        while(l1 || l2){

            if(l1 && l2){
                if(l1->val <= l2->val){
                    newHead->child = l1;
                    newHead = l1;
                    l1 = l1->child;
                }
                else{
                    newHead->child = l2;
                    newHead = l2;
                    l2 = l2->child;
                }
            }
            else if(l1){
                newHead->child = l1;
                break;
            }
            else{
                newHead->child = l2;
                break;
            }
        }

        return returnHead->child;
    }

    ListNode* flattenLinkedList(ListNode* &head) {

        ListNode *prev = head, *curr = head->next, *nextNode = (curr ? curr->next : nullptr);

        while(curr){
            nextNode = curr->next;
            curr = mergedTwoLL(prev, curr);
            prev->next = nullptr;
            prev = curr;
            curr = nextNode;
            // if(curr) cout << curr->val << endl;
        }
        return prev;
    }
};