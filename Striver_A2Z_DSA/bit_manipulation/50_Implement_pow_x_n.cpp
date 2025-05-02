#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool sign = n<0;
        if(sign){
            while(n<0){
                // if(n%2 == -1){
                if(n&-1 == -1){
                    ans *= x;
                    n = n+1;
                }
                else{
                    x *= x;
                    n >>= 1;// n = n/2;
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
                    n >>= 1;// n = n/2;
                }
            }
        }
        if(sign) return 1/ans;
        return ans;
    }
};


