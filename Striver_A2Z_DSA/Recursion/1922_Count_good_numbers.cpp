#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int mod = 1e9+7;
        int myPowhelper(int x, long n) {
            //your code goes here
            if(n==0) return 1;
    
            if(n==2) return ((long)x%mod * x%mod)%mod;
    
            if(n%2 == 0)
                return (long)myPowhelper((long)x*x % mod, n/2) % mod;
            else
                return (long)x*myPowhelper(x, n-1) % mod;
        }
        int countGoodNumbers(long long n) {
            //formula exceeds the time limit
            return ((long)myPowhelper(5, (n+1)/2)%mod * myPowhelper(4, n/2)%mod)%mod;
        }
    };