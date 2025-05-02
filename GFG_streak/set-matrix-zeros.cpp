//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int temp_i, temp_j, n = mat.size(), m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    temp_i = i;
                    temp_j = j;
                    while(temp_i>=0){
                        mat[temp_i][j] = 0;
                        temp_i--;
                    }
                    
                    while(temp_j>=0){
                        mat[i][temp_j] = 0;
                        temp_j--;
                    }
                    
                    // if(i+1 == n-1 ){
                    //     mat[i+1][j] = 0;
                    // }
                    
                    // if(j+1 == m-1 ){
                    //     mat[i][j+1] = 0;
                    // }

                    // temp_i = i;
                    // temp_j = j;
                    
                    // while(temp_i<mat.size()){
                    //     mat[temp_i][j] = 0;
                    //     temp_i++;
                    // }
                    
                    // while(temp_j<mat[i].size()){
                    //     mat[i][temp_j] = 0;
                    //     temp_j++;
                    // }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends