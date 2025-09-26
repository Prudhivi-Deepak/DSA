#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        // basic idea is to convert 0 to 1 
        // so count zeors and if they are >k remove from left untill they are <0
        // but removing untill < 0 doesn't do anything because length decreses we need max length so do if

        int l = 0, r = 0, zero_cnt = 0, n = nums.size(), maxlen = 0;

        while(r<n){

            if(nums[r]==0) zero_cnt++;

            if(zero_cnt>k){
                if(nums[l]==0) zero_cnt--;
                l++;
            }

            if(zero_cnt<=k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }

        return maxlen;

    }
    int longestOnesFirstTry(vector<int>& nums, int k) {
        int maxlen = 0, i = 0, j = 0, noZeros = 0;
        while(j<nums.size()){
            // cout << " i:"<< i << " j:" << j  << " nums[j] : " << nums[j] << " noZeros : "  << noZeros << " k:" << k << endl;
            if(nums[j]==0){
                if(noZeros==k){
                    while(nums[i]==1) i++;
                    i++;
                    // cout << "inside  i:"<< i << " j:" << j  << " nums[j] : " << nums[j] << " noZeros : "  << noZeros << " k:" << k  << endl;
                }
                else{
                    noZeros++;
                }
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
    int longestOnes1(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int> min_heap;

        queue<int> q;
        int maxlen=0,i=0, j=0;

        while(j<nums.size()){
            if(nums[j]==0){
                if(k>0){
                    k--;
                    q.push(j);
                }
                else if(!q.empty()){
                    i = q.front()+1;
                    q.pop();
                    q.push(j);
                }
                else{
                    i=j+1;
                }
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }

        return maxlen;

    }
};