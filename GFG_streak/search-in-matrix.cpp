//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// 3
// 3
// 3
// 1 5 9
// 14 20 21
// 30 34 43
// 4
// 3
// 4
// 1 5 9 11
// 14 20 21 26
// 30 34 43 50
// 42
// 2
// 3
// 87 96 99
// 101 103 111
// 101

// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here

        int i = 0, j = mat[0].size()-1;
        while(i<mat.size() && j>=0){

            if(mat[i][j] == x){
                return true;
            }
            if(mat[i][j] < x){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends