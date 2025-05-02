
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxReach = 0, n = nums.size();
            for(int i=0; i<n; i++){
                // cout << maxReach << ":" << n-1 << endl;
                if(maxReach >= n-1) return true;
                if(maxReach < i ) return false;
                maxReach = max(maxReach, i+nums[i]);
            }
            return false;
        }
    };