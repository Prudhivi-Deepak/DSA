#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lastbit = 1, zerobit = 1, zerobitindex = 1, n = nums.size();
        for (int i = 0; i < n; i++) {
            // cout << nums[i] << endl;
            if (abs(nums[i]) == n) {
                lastbit = -1;
            } else if (abs(nums[i]) == 0) {
                zerobit = -1;
                if (nums[0] > 0) {
                    nums[0] = -nums[0];
                }
                if (nums[abs(nums[i])] == 0) {
                    zerobitindex = -1;
                }
            } else if (nums[abs(nums[i])] >= 0) {
                if (nums[abs(nums[i])] == 0) {
                    zerobitindex = -1;
                } else {
                    nums[abs(nums[i])] = -nums[abs(nums[i])];
                }
            }
        }
        if (zerobit > 0) {
            return 0;
        } else if (lastbit > 0) {
            return n;
        } else {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    if (zerobitindex == -1) {
                        continue;
                    } else {
                        return i;
                    }
                }

                if (nums[i] > 0) {
                    return i;
                }
            }
        }
        return 0;
    }
};