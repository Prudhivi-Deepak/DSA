#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> st;
    
            for(int i=0; i<n; i++){
                st.insert(nums[i]);
            }
    
            int max_count = 0, count = 0;
            for(auto i=st.begin(); i!=st.end(); i++){
                count = 0;
                int x = *i;
                if(st.find(x-1) == st.end()){
                    count++;x++;
                    while(st.find(x)!=st.end()){
                        count++; x++;
                    }
                    max_count = max(max_count, count);
                }
            }
            return max_count;
    
        }
        int longestConsecutive1(vector<int>& nums) {
           sort(nums.begin(), nums.end());
           int max_count = 0, count=1;
        //    for(int i=0; i<nums.size(); i++){
            int i=0;
            while(i<nums.size()){
               while(nums[i ]==nums[i+1]) i++;
               if(nums[i]+1 == nums[i+1]) count++;
               else count=1;
    
               max_count = max(max_count, count);
               i++;
           }
           return max_count;
        }
    };