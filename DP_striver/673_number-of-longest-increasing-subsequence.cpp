#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size(), maxi=1;
            vector<int> dp(n, 1), cnt(n, 1);
    
            for(int ind=1; ind<n; ind++){
                for(int i=0; i<ind; i++){
                    if(nums[i] < nums[ind]){
                        if(dp[i]+1 > dp[ind]){
                            dp[ind] = dp[i]+1;
                            cnt[ind] = cnt[i];
                        }
                        else if(dp[i]+1 == dp[ind]){
                            cnt[ind] += cnt[i];
                        }
                    }
                }
                maxi = max(maxi, dp[ind]);
            }
            int result = 0;
            for(int i=0; i<n; i++){
                if(dp[i] == maxi) result += cnt[i];
            }
            return result;
        }
    };