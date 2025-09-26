#include <bits/stdc++.h>
using namespace std;


class Solution{   
    public:
        bool isSubsetSum(vector<int>arr, int target){
            int n = arr.size();
            // vector<vector<bool>> dp(n, vector<bool>(target+1, false));
            vector<bool> prev(target+1, false), curr(target+1, false);
            // for(int i=0; i<n; i++){
            //     dp[i][0] = true;
            // }
            prev[0] = true;
    
            // if(arr[0] <= target) dp[0][arr[0]] = true;
            prev[arr[0]] = true;
    
            for(int i=1; i<n; i++){
                for(int t=0; t<=target; t++){
                    // bool NT = dp[i-1][t];
                    // bool T = t>=arr[i] ? dp[i-1][t-arr[i]] : false;
                    bool NT = prev[t];
                    bool T = t>=arr[i] ? prev[t-arr[i]] : false;
                    curr[t] = NT||T;
                }
                prev = curr;
            }
            return prev[target];
        }
    };