#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        // decreasing monotonic deque

        deque<int> dq;
        int i = 0, n = arr.size();

        vector<int> windowMax;
        while(i<n){

            // insert from back, remove from front
            // check the window size first - adjusting the window size - first thing
            while(!dq.empty() && dq.front() < i-k+1) dq.pop_front();

            // Now push the i to the dq after removing invalid back entries
            while(!dq.empty() && arr[dq.back()] < arr[i] ) dq.pop_back();

            // Now push the curr element
            dq.push_back(i);

            // we start collecting max from k=3 0 1 2 2nd index = k-1 index
            if(i>=k-1){
                // now take front value whihc is max
                windowMax.push_back(arr[dq.front()]);
            }

            i++;
        }

        return windowMax;
    }
    vector<int> maxSlidingWindowFirstTry(vector<int>& nums, int k) {

        deque<int> dq;
        int i=0;
        vector<int> ans;

        while(i<nums.size()){

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i+1 >=k){
                while(!dq.empty() && dq.back() - dq.front() +1 > k){
                    dq.pop_front();
                }
                if(!dq.empty()) ans.push_back(nums[dq.front()]);
            }
            i++;
        }

        return ans;


        // if (k==1) return nums;
        // int maxi = nums[0];
        // vector<int> ans;
        // for(int i=0; i<k; i++){
        //     maxi = max(maxi, nums[i]);
        // }
        // ans.push_back(maxi);
        // for(int i=k; i<nums.size(); i++){
        //     maxi = max(maxi, nums[i]);
        //     ans.push_back(maxi);+

        // }
        // return ans;
    }
};