#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        double myPowhelper(double x, long n) {
            //your code goes here
            if(n==0) return 1.0;
    
            if(n<0) return 1.0/myPowhelper(x, -1.0*n);
    
            if(n==2) return (double)x*x;
    
            if(n%2 == 0)
                return (double)myPowhelper(x*x, n/2);
            else
                return (double)x*myPowhelper(x, n-1);
        }
        double myPow(double x, int n) {
            return myPowhelper(x, n);
        }
        double myPow1(double x, int n) {
            double ans = 1;
            bool sign = n<0;
            // if(sign) n = -n;
            if(sign){
                while(n<0){
                    // if(n%2 == -1){
                    if(n&-1 == -1){
                        ans *= x;
                        n = n+1;
                    }
                    else{
                        x *= x;
                        // n = n/2;
                        n >>= 1;
                    }
                }
            }
            else{
                while(n>0){
                    // if(n%2 == 1){
                    if(n&1){
                        ans *= x;
                        n = n-1;
                    }
                    else{
                        x *= x;
                        // n = n/2;
                        n >>= 1;
                    }
                }
            }
            if(sign) return 1/ans;
            return ans;
        }
    };