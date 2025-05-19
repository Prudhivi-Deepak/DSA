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
        bool isPalindrome(ListNode* head) {
            vector<int> v;
            while(head){
                v.push_back(head->val);
                head = head->next;
            }
    
            int i=0, j = v.size()-1;
            while(i<j){
                if(v[i]!=v[j]) return false;
                i++;j--;
            }
            return true;
        }
        bool isPalindrome1(ListNode* head) {
            int length = 0;
            ListNode* temp = head;
            while (temp != NULL) {
                length++;
                temp = temp->next;
            }
    
            if (length == 1) return true;
    
            // cout << "length : " << length << endl;
            int odd_or_even = length % 2;  // 0-even, 1-odd
            length = length / 2;
            stack<int> st;
            temp = head;
            if (odd_or_even) {
                while (length > 0) {
                    st.push(temp->val);
                    temp = temp->next;
                    length--;
                }
                temp = temp->next;
            } else {
                while (length > 0) {
                    st.push(temp->val);
                    temp = temp->next;
                    length--;
                }
            }
    
            // if (temp != NULL)
            //     cout << "temp -> val : " << temp->val << endl;
            // else
            //     cout << "temp is NULL";
    
            while (temp != NULL && !st.empty() && st.top() == temp->val) {
                temp = temp->next;
                st.pop();
            }
    
            if (temp == NULL)
                return true;
            else
                return false;
        }
    };