class Solution {
public:
    int nCr(int n, int r){
        int ans = 1;
        for(int i=1; i<=r; i++){
            ans *= (n-i+1);
            ans /= i;
        }
        return ans;
    }

    int pascalTriangleI(int r, int c) {

        //    0 1 2 3
        // 0  1
        // 1  1 1
        // 2  1 2 1
        // 3  1 3 3 1
        // ncr = 2c2 = 2/2! * 0!= 2/2 = 1
        // 3c2 = 3!/2!*1! = 6/2 = 3
        // 5c2 = 5!/3!2! instead do 5x4/1x2 = 10
        return nCr(r-1, c-1);
    }
};