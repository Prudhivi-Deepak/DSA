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
    ListNode *reverseK(ListNode *prev, ListNode *curr, ListNode *currNext){
        ListNode *last = nullptr, *currNode = prev, *nextNode = currNode->next;

        // nullptr <- 1 <-2 3(nn)

        while(currNode != currNext){
            // cout << currNode->val << " -> " << (last ? last->val : -1) << endl;
            currNode->next = last;

            last = currNode;
            currNode = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        // cout << prev->val << " -> " << (currNext ? currNext->val : -1) << endl;
        prev->next = currNext;
        return currNext;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *newHead = nullptr;
        int cnt = 1;

        ListNode *curr = head, *prev = head, *prevEnd = nullptr;

        while(curr){
            if(cnt%k==0){
                // cout << prev->val << " : " << curr->val << " : " << ((curr->next) ? curr->next->val : -1) << endl;
                if(newHead==nullptr) newHead = curr;
                ListNode *newcurr = reverseK(prev, curr, curr->next);
                if(prevEnd) prevEnd->next = curr;
                prevEnd = prev;
                curr = prev = newcurr;
            }
            else{
                curr = curr->next;
            }
            cnt++;
        }

        return newHead;

        // first kth node is always my new head

        // head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
        // iterate from head to end with counter cnt%k == 0, that's where
        // you have to reverse currNode and prev node

        // head -> 1 -> 2 -> 3 -> 4 -> 5
        //            c(2)
        //         p 

        // send the prev and currNode and next pointer as well to a function to reverse them
        // and return the next pointer

        // head -> nullptr <- 1 <- 2 -> 3 -> 4 -> 5
        // head -> 2 -> 1 -> 3 -> 4 -> 5
        //                       c(4)
        //                   p
        // head -> 2 -> 1 -> 4 -> 3 -> 5
        //                             c(5)
        //                             p






    }
};