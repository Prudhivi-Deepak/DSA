
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include<bits/stdc++.h>
using namespace std;


struct Compare{ 
    bool operator()(ListNode * l1, ListNode * l2){
        return l1->val > l2->val;
    }
 };

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto compare = [](ListNode * l1, ListNode * l2){
            return l1->val > l2->val;
        };

        // priority_queue<ListNode *, vector<ListNode *>, Ccompare> min_heap;
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> min_heap(compare);
        for(ListNode *l : lists){
            if(l!=nullptr)
                min_heap.push(l);
        }

        // 1->4->5->nullptr
        // 1->3->4->nullptr
        // 2->6->nullptr

        //root = curr->next;
        //curr 0->nullptr
        //    curr 
        //0->  1->  4->  5->  nullptr

        ListNode *root = new ListNode();
        ListNode *curr = root;


        while(!min_heap.empty()){
            // cout << min_heap.top()->val << endl;
            curr->next = min_heap.top();
            curr = curr->next;
            min_heap.pop();
            if(curr!=nullptr && curr->next != nullptr)
                min_heap.push(curr->next);
        }
        return root->next;
    }
};