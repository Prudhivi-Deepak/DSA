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

    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            vector<int> row;
            for(int c=0; c<=i; c++){
                row.push_back(nCr(i, c));
            }
            ans.push_back(row);
        }

        return ans;
    }
};