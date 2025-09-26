#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 1; N <= n; N++) {
          dp[0][N] = N*price[0];
        }

        for (int i = 1; i < n; i++) {
            for (int N = 1; N <= n; N++) {
                int NT = dp[i - 1][N];
                int T = N >= (i + 1) ? price[i] + dp[i][N - (i + 1)] : 0;
                dp[i][N] = max(NT, T);
            }
        }

        return dp[n - 1][n];
    }
};
