#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int houseRobber(vector<int>& money) {
            if(money.size()==1) return money[0];
            vector<int> temp = money;
            temp.erase(temp.begin(),temp.begin()+1);
            money.pop_back();
    
            return max(houseRobberHelper(temp), houseRobberHelper(money));
        }
        int houseRobberHelper(vector<int>& money) {
            int n = money.size();
            vector<int> dp(n+2, 0);
            for(int i=n-1; i>=0; i--){
                int nottake = dp[i+1];
                int take = money[i]+dp[i+2];
                dp[i] = max(nottake, take);
            }
    
            return dp[0];
        }
        int nonAdjacent(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+2, 0);
            for(int i=n-1; i>=0; i--){
                int nottake = dp[i+1];
                int take = nums[i]+dp[i+2];
                dp[i] = max(nottake, take);
            }
            return dp[0];
        }
    };