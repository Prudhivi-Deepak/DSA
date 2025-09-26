#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // 7 1 5 3 6 4
            int minimum = prices[0];
            int profit = 0;
            for(int i: prices){
                profit = max(profit, i-minimum);
                minimum = min(i, minimum);
            }
            return profit;
        }
    };