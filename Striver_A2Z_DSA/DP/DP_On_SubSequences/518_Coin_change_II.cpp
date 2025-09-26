// https://leetcode.com/contest/weekly-contest-455/problems/inverse-coin-change/ -->weekly contest related problem
// https://leetcode.com/problems/inverse-coin-change/ --> check other approach also
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // int coinChange(vector<int>& coins, int amount) {
        int change(int amount, vector<int>& coins) {
            // if(amount==0) return 0;
            int n = coins.size();
            // vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
            vector<unsigned int> prev(amount+1, 0), curr(amount+1, 0);
            for(int a=0; a<=amount; a++){
                if(a%coins[0]==0) prev[a] = 1;
            }
    
            // for(int i=1; i<n; i++)
            prev[0] = 1;
    
            for(int i=1; i<n; i++){
                curr[0] = 1;
                for(int a=1; a<=amount; a++){
                    unsigned int NT = prev[a];
                    unsigned int T = (a>=coins[i]) ? (curr[a-coins[i]]) : 0;
                    curr[a] = NT+ T;
                }
                prev = curr;
            }
            return prev[amount];
        }
    };