#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumMountainRemovals(vector<int>& nums) {
            int n = nums.size(), ind_inv=0, i_inv=0 ;
    
            vector<int> inc_dp(n, 1);
            vector<int> dec_dp(n, 1);

                    // 2 1 1 5 6 2 3 1
            //ind   // 0 1 2 3 4 5 6 7
            //         7 6 5 4 3 2 1 0
            // n = 8 ind = 0 ==> n-ind-1 ==> 8-0-1 = 7
            
            for(int ind=1; ind<n; ind++){
                for(int i=0; i<ind; i++){
                    if(nums[i]<nums[ind] && inc_dp[i]+1 > inc_dp[ind]){
                        inc_dp[ind] = 1+inc_dp[i];
                    }
    
                    ind_inv = n-ind-1;
                    i_inv = n-i-1;
                    // cout << "ind : " << ind << " i : " << i << endl;
                    cout << "ind_inv : " << ind_inv << " i_inv : " << i_inv << endl;
    
                    if(nums[i_inv]<nums[ind_inv] && dec_dp[i_inv]+1 > dec_dp[ind_inv]){
                        dec_dp[ind_inv] = 1+dec_dp[i_inv];
                    }
                }
            }
            int maxi = 0;
            for(int ind=0; ind<n; ind++){
                if(inc_dp[ind] ==1 || dec_dp[ind]==1) continue;
                maxi = max(maxi, inc_dp[ind]+dec_dp[ind]-1);
            }
            return n-maxi;
        }
    };