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

    vector<int> pascalTriangleII(int r) {

        vector<int> ans;

        for(int c=0; c<r; c++ ){
            ans.push_back(nCr(r-1, c));
        }
        return ans;
    }
};