class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here

        // x   n    base    ans
        // 2   6/2   2       1
        // 2   3-1   2*2=4   1
        // 2   2/2   4       1*4 = 4
        // 2   1-1   4*4=16  4
        // 2   0     16      4*16=64
        // ans = 64

        double base = x, ans = 1;
        if(n<0) return 1/pow(x, -n);

        while(n){
            if(n&1){
                ans *= base;
                n--;
            }
            else{
                base *= base;
                n/=2;
            }
        }
        return ans;
    }
};