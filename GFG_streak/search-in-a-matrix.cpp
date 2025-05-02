//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
//         3 30 38 20 52 54 35 60 69
//         0 1  2  3  4  5  6  7  8
        
//         3  30  38  20  52  54  35  60  69
//         00 01  02  10  11  12  20  21  22
// i*r+j = 0  1    2   3   4   5   6   7   8(n*m-1)
//         62
        
//         n - rows
//         m - columns
        
//         (8-j)/r = i
        
//         8-i*r = j
        
//         4 = mid = 4/3 = 1 = i
        
//         4-i*r = j
//         4-1(3) = j
//         4-3 = j
//         1 = j
        
        
        
        
//         0*3+1*3 = 3
        
//         6-1 = 5

// 3
// 3
// 3
// 3 30 38 
// 20 52 54 
// 35 60 69
// 62
// 2
// 3
// 18 21 27
// 38 55 67
// 55
// 3
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3
        
        int i=0, n=mat.size(), j=mat[0].size()-1, mid;

        while(i<n && j>=0){
            if(mat[i][j] == x){
                return true;
            }
            else if(mat[i][j] < x){
                i++;
            }
            else{
                j--;
            }
        }

        return false;

        // for(int row=0; row<n; row++){
        //     i = 0;
        //     j = m;
        //     while(i<=j){
        //         mid = (i+j)/2;
        //         if(mat[row][mid] == x){
        //             return true;
        //         }
        //         else if(mat[row][mid] < x){
        //             i = mid+1;
        //         }
        //         else{
        //             j = mid-1;
        //         }
        //     }
        // }
        
        // return false;


        // while(i<=j){
        //     cout << "i : " << i << " j : " << j << endl;
        //     mid = (i+j)/2;
        //     mid_r = mid/m;
        //     mid_c = mid-(mid_r*m);
        //     cout << "m_r : " << mid_r  << " m_c : " << mid_c << " mat[mid_r][mid_c] : " << mat[mid_r][mid_c] <<  endl;
        //     if(mat[mid_r][mid_c] == x){
        //         return true;
        //     }
        //     else if(mat[mid_r][mid_c] < x){
        //         i = mid+1;
        //     }
        //     else{
        //         j = mid-1;
        //     }
        // }
        
        // return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends