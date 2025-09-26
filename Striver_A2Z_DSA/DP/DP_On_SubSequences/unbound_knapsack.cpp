#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
     int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
         vector<vector<int>> dp(n, vector<int>(W+1, 0));
 
         for(int w=0; w<=W; w++){
             dp[0][w] = (w/wt[0])*val[0];
         }
 
         for(int i=1; i<n; i++){
             for(int w=0; w<=W; w++){
                 int NT = dp[i-1][w];
                 int T = w>=wt[i] ? val[i]+dp[i][w-wt[i]] : 0;
                 dp[i][w] = max(NT, T);
             }
         }
         return dp[n-1][W];
     }
     bool static compare(pair<int, int> p1, pair<int, int> p2) {
         return (double)p1.second / p1.first > (double)p2.second / p2.first;
     }
     int unboundedKnapsackFirstTry(vector<int>& wt, vector<int>& val, int n,
                                   int W) {
         vector<pair<int, int>> p;
 
         for (int i = 0; i < n; i++) {
             p.push_back({wt[i], val[i]});
         }
 
         sort(p.begin(), p.end(), compare);
 
         int Totalval = 0;
 
         for (pair<int, int> p1 : p) {
             cout << " ----------------------- " << endl;
             cout << p1.first << " wt available " << ", " << p1.second << " :"
                  << (double)p1.second / p1.first << " V per 1wt" << endl;
             cout << W << "/" << p1.first << endl;
             int howmany = (W / p1.first);
             cout << "howmany : " << howmany << endl;
             int multiple = howmany * p1.first;
             cout << "multiple : " << multiple << endl;
             if (W <= 0) break;
             W = W - (multiple);
             cout << "W: " << W << endl;
             Totalval += howmany * p1.second;
             cout << "Totalval : " << Totalval << endl;
         }
 
         return Totalval;
     }
 };
 