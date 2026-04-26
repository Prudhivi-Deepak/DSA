class Solution {
public:
    int divide(int dividend, int divisor) {
        //your code goes here

        int i=0, sum = 0;

        // 10

        // 8 4 2 1
        // 0 0 1 1 --> 3
        // 0 1 1 0 --> 6 --> i=1 sum += 
        // 1 1 0 0 --> 12

        if(dividend == INT_MIN && divisor==-1) return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);

        long N = labs(dividend);
        long D = labs(divisor);

        while(N >= D){
            i=0;
            // while((D<<i) <= N ){
            //     i++;
            // }
            while(i<31 && (D<<i) <= N) i++;
            
            N = N - (D<<(i-1));
            sum += (1<<(i-1));
        }
        return sign ? -sum : sum;

        // 49 8
        // 8**1 = 8
        // 8**2 = 64

        // 32 16 8 4 2 1
        // 0  0  1 0 0 0 (8<<0)
        // 0  1  0 0 0 0 (8<<1)
        // 1  0  0 0 0 0 (8<<2)
        // so i = 2 where it equals 32 sum = 2^i = 2^2 = 4

        // so do 49-32 = 17 = divided and divisor = 8 (same)

        // 17
        // 32 16 8 4 2 1
        // 0  0  1 0 0 0 (8<<0)
        // 0  1  0 0 0 0 (8<<1)
        // so i=1 where it equals 16 sum = 4 + 2^1 = 6 --> super this si answer

        // 17-16 = 1 and divisor = 8

        // if dividend < divisor we return the sum




    }
};