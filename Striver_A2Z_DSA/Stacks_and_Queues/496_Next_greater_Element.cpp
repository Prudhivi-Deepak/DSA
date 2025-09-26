#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
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