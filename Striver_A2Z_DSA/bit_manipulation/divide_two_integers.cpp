#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // convert to long to prevent overflow
        long a = labs(dividend);
        long b = labs(divisor);
        long q = 0;

        // determine the sign of the result
        bool sign = (dividend < 0) ^ (divisor < 0);  // XOR for sign

        while (a >= b) {
            int i = 0;
            while ((i < 31) && ((b << i) <= a)) {
                i++;
            }
            i--; // go back to the last valid shift
            a -= (b << i);
            q += (1 << i); // add 2^i to quotient
        }

        return sign ? -q : q;
    }
};
    