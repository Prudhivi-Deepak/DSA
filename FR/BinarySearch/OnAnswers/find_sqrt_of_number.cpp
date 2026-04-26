class Solution {
public:
    int floorSqrt(int n)  {

        // we know sqrt root of n is some where around 1 to n right
        // check for mid*mid == n
        // bacsed on the value mid*mid --> go and cehck left half or right half

        if(n<2) return n;

        int l = 1, r = n, mid, index = n;

        while(l<=r){
            mid = l+(r-l)/2;
            if(mid <= n/mid){
                // floor value
                index = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return index;    
    }
};