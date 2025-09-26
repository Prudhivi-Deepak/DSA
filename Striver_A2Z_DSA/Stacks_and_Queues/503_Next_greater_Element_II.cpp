
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int> st;
            int i = 2*nums.size()-1, ind;
            vector<int> ans(nums.size(), -1);
            while(i>=0){
    
                ind = i%nums.size();
    
                if(!st.empty() && st.top() > nums[ind])
                    ans[ind] = st.top();
                else if(!st.empty()){
                    while(!st.empty() && st.top() <= nums[ind]){
                        st.pop();
                    }
                    if(!st.empty()){
                        ans[ind] = st.top();
                    }
                }
                st.push(nums[ind]);
                i--;
            }
            return ans;
        }
    
        vector<int> nextGreaterElements1(vector<int>& nums) {
            stack<int> st;
            int i = nums.size()-1, sInd_flag = -1, sInd = -1;
            vector<int> ans(i+1, -1);
            while(i>=0){
                // cout << i << " : " << nums[i] << " : ";
                // if (!st.empty()) cout << st.top() << endl;
                // else cout << "Empty" << endl;
    
                if(!st.empty() && st.top() > nums[i])
                    ans[i] = st.top();
                else if(!st.empty()){
                    // cout << "inside else " << endl;
                    while(!st.empty() && st.top() <= nums[i]){
                        // cout << "st.top : " << st.top() << endl;
                        st.pop();
                    }
                    if(!st.empty()){
                        // cout << "if st.top : " << st.top() << endl;
                        ans[i] = st.top();
                    }
                }
    
                if(ans[i]==-1 && sInd_flag == -1) sInd = i;
                st.push(nums[i]);
                i--;
                if(i==-1 && sInd_flag==-1){
                    i=nums.size()-1;
                    sInd_flag = 1;
                }
                else if(i==sInd && sInd_flag==1) break;
    
                // cout << i << " : " << nums[i] << " : ";
                // if (!st.empty()) cout << st.top() << endl;
                // else cout << "Empty" << endl;
                // cout << "-------------" << endl;
            }
    
            // i=sInd;
    
            // if(i!=-1){
            //     while(i>=0 || i>=sInd){
        
            //         if(!st.empty() && st.top() > nums[i])
            //             ans[i] = st.top();
            //         else if(!st.empty()){
            //             while(!st.empty() && st.top() < nums[i]){
            //                 st.pop();
            //             }
            //             if(!st.empty())
            //                 ans[i] = st.top();
            //         }
    
            //         if(ans[i]==-1) sInd = i;
    
            //         st.push(nums[i]);
            //         i--;
            //         if(i==-1){
            //             i=n-1;
            //         }
            //     }
            // }
    
    
    
            return ans;
        }
    };