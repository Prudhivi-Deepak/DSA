#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
        // 1 3 2 4
        
        //  5 2 1 3 4
        // -1 3 3 4 -1

        // stack  curr nge
        // EMP     4    -1  ==> 4    4    -1
        // 4       3    3 ==> 4 3    3     3
        // 4 3     1    3 ==> 4 3 1  1     3
        // 4 3 1   2   
        // 4 3     2    3 ===> 4 3 2  2      3
        // 4 3 2   5      
        // 4 3     5      
        // 4       5      
        //         5    -1 ==> 5      5    -1

        int n=nums2.size(), i = n-1;
        stack<int> st;
        // vector<int> nge(n, -1);
        unordered_map<int,int> umap;

        while(i>=0){

            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            // nge[i] = st.empty() ? -1 : st.top();
            umap[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
            i--;
        }

        vector<int> nge;
        for(auto i : nums1){
            nge.push_back(umap[i]);
        }

        return nge;
    }
    vector<int> nextGreaterElementFirstTry(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> umap;
        vector<int> ans;
        int i=nums2.size()-1;
        while(i>=0){
            if(st.empty())
                umap[nums2[i]] = -1;
            else if(st.top()>nums2[i])
                umap[nums2[i]] = st.top();
            else{
                while(!st.empty() && st.top()<nums2[i])
                    st.pop();
                
                if(st.empty())
                    umap[nums2[i]] = -1;
                else
                    umap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
            // cout << nums2[i] << " : " << umap[nums2[i]] << endl;
            i--;
        }
        
        for(int i: nums1){
            ans.push_back(umap[i]);
        }

        return ans;
    }
};