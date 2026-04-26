// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // head -> 2 -> 4 -> 7 -> 9
        //         l1
        // head -> 1 -> 2 -> 5 -> 6
        //              l2
        // newhead -> -1 -> 1 -> nullptr
        ListNode *l1 = list1, *l2 = list2, *newHead = new ListNode(-1);
        ListNode *returnHead = newHead;

        while(l1 || l2){
            if(l1 && l2){
                // cout << l1->val << " : "<< l2->val << endl;
                if(l1->val <= l2->val){
                    newHead->next = l1;
                    newHead = l1;
                    l1 = l1->next;
                }
                else{
                    newHead->next = l2;
                    newHead = l2;
                    l2 = l2->next;
                }
            }
            else if(l1){
                newHead->next = l1;
                break;
            }
            else{
                newHead->next = l2;
                break;
            }
        }
        return returnHead->next;
    }
};