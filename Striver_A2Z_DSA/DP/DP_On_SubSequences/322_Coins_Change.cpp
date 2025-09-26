#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Revision
        int coinChange(vector<int>& coins, int amount) {
            // if(amount==0) return 0;
            int n = coins.size();
            // vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
            vector<int> prev(amount+1, 1e9), curr(amount+1, 1e9);
            for(int a=0; a<=amount; a++){
                if(a%coins[0]==0) prev[a] = a/coins[0];
            }
    
            // for(int i=1; i<n; i++)
            prev[0] = 0;
    
            for(int i=1; i<n; i++){
                curr[0] = 0;
                for(int a=1; a<=amount; a++){
                    int NT = prev[a];
                    int T = (a>=coins[i]) ? (1+curr[a-coins[i]]) : 1e9;
                    curr[a] = min(NT, T);
                }
                prev = curr;
            }
            return (prev[amount]==1e9) ? -1 : prev[amount];
        }
        int coinChangeFirstTry(vector<int>& coins, int sum) {
            int n = coins.size();
            vector<int> curr(sum+1, INT_MAX);
            curr[0] =  0;
            for(int i = n-1; i>=0; i--){
                curr[0] = 0;
                for(int s=0; s<=sum; s++){
                    if(s>=coins[i] && curr[s-coins[i]]!=INT_MAX)
                        curr[s] = min(curr[s - coins[i]]+1, curr[s]);
                }
            }
            if(curr[sum]==INT_MAX) return -1;
            return curr[sum];
        }
    };