struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        ListNode * findMiddle(ListNode *head){
            ListNode *first = head->next, *second = head;
    
            if(first==NULL) return head;
    
            while(first->next && first->next->next){
                second = second->next;
                first = first->next->next;
            }
            return second;
        }
    
        ListNode* mergeLL(ListNode *tempFLL, ListNode *tempSLL){
    
            ListNode *tempLL = new ListNode(-1); //dummy head node
            ListNode *returnPointerHead = tempLL;
    
            while(tempFLL && tempSLL){
                if(tempFLL->val <= tempSLL->val){
                    tempLL->next = tempFLL;
                    tempFLL = tempFLL->next;
                }
                else{
                    tempLL->next = tempSLL;
                    tempSLL = tempSLL->next;
                }
                tempLL = tempLL->next;
            }
    
            if(tempFLL) tempLL->next = tempFLL;
    
            if(tempSLL) tempLL->next = tempSLL;
    
            return returnPointerHead->next;
        }
    
        ListNode*  DivideLL(ListNode * head){
    
            if(head==NULL || head->next==NULL) return head;
    
            ListNode* middleEle = findMiddle(head);
    
            ListNode *SecondLLhead = middleEle->next; middleEle->next = NULL;
            ListNode *FirstLLHead = head;
    
            FirstLLHead = DivideLL(FirstLLHead);
            SecondLLhead = DivideLL(SecondLLhead);
    
            return mergeLL(FirstLLHead, SecondLLhead);
        }
    
        ListNode* sortList(ListNode* head) {
            return DivideLL(head);
        }
    };