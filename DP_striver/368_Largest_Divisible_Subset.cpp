#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            // 0  1 2 3 4 5  6  7
            // 10 9 2 5 3 7 101 18
            // 1  1 1 1 1 1  1   1
        // 1// 1  1 1 2 2 2  2   2
        //                3  2   2
        //                3  2   2
        //                   3   3
        //                   3   3
        //                   4   4
    
        //     1  1 1 2 2 3  4   4
        //     0  1 2 3 4 5  6   7
        //     0  1 2 2 2 4  5   5
    
        //  index 101 -> 5 4 2 
        //         101   7 3 2 
    
        // 2 5 7 101
    
            sort(nums.begin(), nums.end());
    
            int maxi = 1, maxi_ind = 0, n = nums.size();
            vector<int> hash(n, 0);
            vector<int> dp(n, 1);
    
            for(int ind=1; ind<n; ind++){
                int temp = dp[ind];
                hash[ind] = ind;
                for(int i=0; i<ind; i++){
                    if(nums[ind] % nums[i] == 0 && temp+dp[i] > dp[ind] ){
                        dp[ind] = temp+dp[i];
                        hash[ind] = i;
                    }
                }
                // maxi = max(maxi, dp[ind]);
                // maxi_ind = ind;
                if(dp[ind] > maxi){
                    maxi = dp[ind];
                    maxi_ind = ind;
                }
            }
            
            vector<int> temp;
            temp.push_back(nums[maxi_ind]);
            while(hash[maxi_ind] != maxi_ind){
                temp.push_back(nums[hash[maxi_ind]]);
                maxi_ind = hash[maxi_ind];
            }
    
            reverse(temp.begin(), temp.end());
            return temp;
            // 0 1 2
            // 1 2 3
            // 1 1 1
            // 1 2 3
            // 0 0 1
        }
    };