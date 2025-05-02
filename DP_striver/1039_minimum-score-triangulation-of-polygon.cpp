#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        if (i == j)
            return 0;
        int steps = 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int k = i; k < j; k++) {
            steps =
                min(steps, values[i - 1] * values[k] * values[j] +
                               f(i, k, values, dp) + f(k + 1, j, values, dp));
        }
        return dp[i][j] = steps;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(), steps;
        vector<vector<int>> dp(n, vector(n, 0));

        for (int i = n - 1; i > 0; i--) {
            for (int j = i+1; j < n; j++) {
                // cout << i << j << endl;
                if (i != j) {
                    steps = 1e9;
                    for (int k = i; k < j; k++) {
                        steps =min(steps, values[i - 1] * values[k] * values[j] +dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = steps;
                }
            }
        }
        return dp[1][n - 1];
        // return f(1, n-1, values, dp);
    }
};