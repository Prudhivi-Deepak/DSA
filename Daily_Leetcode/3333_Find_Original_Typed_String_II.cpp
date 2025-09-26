#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define ll long long
    // recursive approach 
    // ll ways(vector<int> & freq,int i,int sum){
    //     int n = freq.size();
    //     ll mod = 1e9+7;
    //     if(sum<0) return 0 ;
    //     if(i>=n && sum>=0) return 1 ;
    //     if(dp[i][sum] !=-1) return dp[i][sum] ;
    //     ll ans=0;
    //     for(int pick =1;pick<=freq[i];pick++){
    //         ans += ways(freq,i+1,sum-pick) % mod;
    //     }
    //     return dp[i][sum] = ans % mod;
    // }

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if(n==0) return 0;
        ll mod = 1e9+7;
        if(n==k) return 1;
        if(n<k) return 0;
        vector<int> freq;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && word[j]==word[i]) j++;
            freq.push_back(j-i);
            i=j;
        }
        ll prod=1;
        for(auto x:freq) prod = ( prod * x ) % mod ;
        if(k<freq.size()) return prod; 
        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int num : freq) {
            vector<int> newDp(k, 0);
            long long sum = 0;
            for (int s = 0; s < k; ++s) {
                if (s > 0) sum = (sum + dp[s - 1]) % mod;
                if (s > num) sum = (sum - dp[s - num - 1] + mod) % mod;
                newDp[s] = sum;
            }
            dp = newDp;
        }

        long long invalid = 0;
        for (int s = freq.size(); s < k; ++s)
            invalid = (invalid + dp[s]) % mod;

        return (prod - invalid + mod) % mod;



     
    }
};