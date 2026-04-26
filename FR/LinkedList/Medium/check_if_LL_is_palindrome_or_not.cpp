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
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    void printLL(ListNode *head1){
        while(head1){
            cout << head1->val << " ";
            head1 = head1->next;
        }
        cout << endl;
    }

    ListNode *ReverseLL(ListNode *CurrNode){
        // ListNode *slow = currNode, *prev = slow, *curr = slow->next, *nextNode = (curr ? curr->next : nullptr);
        ListNode *prev = nullptr, *curr = CurrNode, *nextNode = (curr ? curr->next : nullptr);
        // currNode->next = nullptr;
        
        while(curr){
            curr->next = prev;

            prev = curr;
            curr = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // find middle
        ListNode *fast = head, *slow = head;

        if(head->next == nullptr) return true;
        // if(head->next->next == nullptr){
        //     return head->val == head->next->val;
        // }

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        // cout << slow->val << endl;

        // reverse second half
        ListNode *prev = ReverseLL(slow);

        // printLL(head);
        // printLL(prev);

        // now check if palindrome or not 
        bool isPalindrome = true;
        ListNode *first = head, *second = prev;

        while(second){
            if(first->val != second->val){
                isPalindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // now reverse the second half
        // ListNode *prev1 = nullptr, *curr1 = prev, *nextNode1 = curr1->next;
        
        // while(prev1 != slow){
        //     curr1->next = prev1;

        //     prev1 = curr1;
        //     curr1 = nextNode1;
        //     if(nextNode1) nextNode1 = nextNode1->next;
        // }
        ReverseLL(prev);
        

        // curr1->next = prev1;

        // printLL(head);

        return isPalindrome;

        // head -> 3 -> 7 -> 5 -> 7 -> 3 -> NULL
        //                             f
        //                   s
        //                   s->next = NULL
        // head -> 3 -> 7 -> 5 -> NULL 7 -> 3 -> NULL
        //                   p    c    n 
        // head -> 3 -> 7 -> 5 <- 7 -> 3 -> NULL
        //                         p    c    n 
        // head -> 3 -> 7 -> 5 <-> 7 <- 3 -> NULL
        //                              p    c    n 
        // head -> 3 -> 7 -> 5 <-> 7 <- 3 -> NULL

        // first = head, second = prev
        // head -> 3 -> 7 -> 5 <- 7 <- 3 -> NULL
        //         f                   s

        // head -> 3 -> 7 -> 5 <- 7 <- 3 -> NULL
                         //  s         p


        // 1 -> 1 -> 2 -> 1 -> NULL
        //                     f
        //           s
        //           s->next = NULL
        // 1 -> 1 -> 2 -> (NULL) 1 -> NULL
        //           p           c     n 
        // 1 -> 1 -> 2 <- 1 -> NULL
        //                p    c n
        // 1 -> 1 -> 2 <- 1 -> NULL
        // f              s 

        








        
    }
};