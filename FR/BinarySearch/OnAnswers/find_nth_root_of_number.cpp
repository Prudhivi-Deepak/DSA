class Solution {
public:

  long long funN(int x, int n, int M){
    // cout << x << " ^ "<< n << " = ";
    long long base = x, ans = 1;

    while(n){
        if(n%2){
            ans *= base;
            n--;
        }
        else{
            base *= base;
            n /= 2;
        }
        if(ans>M || base>M) return M+1;
    }
    // cout << ans << endl;
    return ans;
    // int ans = 1;
    // for(int i=0; i<n; i++){
    //     ans = ans*x;
    // }
    // return ans;
  }

  int NthRoot(int N, int M) {

        if(M==1) return 1;
        if(N==1) return M;
       
    //    same as sqrt but here we use seperate function for mid**n right?
        long long l = 1, r = M/2, mid;

        while(l<=r){
            mid = l+(r-l)/2;

            long long midN = funN(mid, N, M);

            if(midN == M ) return mid;
            else if(midN < M){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
};
