#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        // 0 1  2 3 4 5 6 7 8 9 10  11 12 13 14 15 16 17 18 19 20 21
        // 3 10 4 2 1 2 6 1 7 2  9  3  10  4  2  1  2  6  1  7  2  9
        //                     9 10  10 -1  6  6  2  6  7  7  9  9 -1

        stack<int> st;
        int n = nums.size(), i = 2*n-1;
        vector<int> nge(n);

        while(i>=0){
            int curr = nums[i%n];

            while(!st.empty() && st.top() <= curr ){
                st.pop();
            }

            nge[i%n] = st.empty() ? -1 : st.top();

            st.push(curr);
            i--;
        }
        return nge;
    }
    vector<int> nextGreaterElementsFirstTry(vector<int>& nums) {
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