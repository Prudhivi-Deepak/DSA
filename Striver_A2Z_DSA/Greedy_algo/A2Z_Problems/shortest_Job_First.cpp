#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here

        sort(bt.begin(), bt.end());
        long long n = bt.size();
        long long total_wt = 0, curr_wt = 0;
        for(long long i=1; i<n; i++){
            curr_wt += bt[i-1];
            total_wt += curr_wt;
        }
        return ceil(total_wt/n);
        // 4 1 3 7 2
        // 1 2 3 4 7

        // 0 1 3 6 10 = 20 --> awt = 4

        // 1 2 3 4
        // 0 1 3 6 = 10/4 = 2

        // 9 3 1 8 2
        // 1 2 3 8 9
        // 0 1 3 6 14 = ceil(24/5) = 4 

    }
};