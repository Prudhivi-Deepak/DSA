// https://leetcode.com/contest/weekly-contest-455/problems/inverse-coin-change/ -->weekly contest related problem
// https://leetcode.com/problems/inverse-coin-change/ --> check other approach also
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

class Solution {
public:
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
    
    vector<int> findCoinsFirstTry(vector<int>& numWays) {
        vector<int> coins;
        int n = numWays.size();

        for(int i=0; i<n; i++){
            if(numWays[i]!=0){
                if(coins.empty() ) coins.push_back(i+1);
                // else{
                    int calculatedWays = change(i+1, coins);
                    if(calculatedWays==numWays[i]){
                        continue;
                    }
                    else if(calculatedWays+1 == numWays[i]){
                        coins.push_back(i+1);
                    }
                    else{
                        return {};
                    }
                // }
            }
            else if(!coins.empty() && change(i+1, coins)!=0) return {};
        }
        return coins;
    }
     vector<int> findCoins(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ways(n + 1, 0);
        ways[0] = 1;
        vector<int> coins;

        for (int a = 1; a <= n; a++) {
            ll want = nums[a - 1];
            ll have = ways[a];
            ll dif = want - have;

            if(dif==1){
                coins.push_back(a);
                cout << a << endl;
                for (int j = a; j <= n; j++) {
                    ways[j] += ways[j - a];
                    cout << ways[j] << " ";
                }
            }
            else if(dif!=0) return {};
            cout << endl;
        }

        return coins;
    }
};