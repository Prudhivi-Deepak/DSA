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
    vector<int> LLTraversal(ListNode *head) {
        ListNode *tempH = head;
        vector<int> ans;
        while(tempH){
            ans.push_back(tempH->data);
            tempH = tempH->next;
        }
        return ans;
    }
};