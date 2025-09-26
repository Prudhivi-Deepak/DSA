#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
        void setZeroes(vector<vector<int>>& matrix) {
            // vector<int> row, col; 
            bool firstRowZero = false, firstColZero = false;
            int m = matrix.size(), n= matrix[0].size();
    
            for (int i = 0; i < m; i++) 
               if (matrix[i][0] == 0) {firstColZero = true;break;}
            
            for (int j = 0; j < n; j++)
                if (matrix[0][j] == 0) {firstRowZero = true;break;}
    
            for(int i=1; i<m; i++){
                for(int j=1; j<n; j++){                
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                        // row.push_back(i);
                        // col.push_back(j);
                    }
                }
            }
    
            for(int i=1; i<m; i++){
                for(int j=1; j<n; j++){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j]=0;
                    // row.push_back(i);
                    // col.push_back(j);
                }
            }
    
            if(firstRowZero)
                for(int col=0; col<n; col++) matrix[0][col] = 0;
            if(firstColZero)
                for(int row=0; row<m; row++) matrix[row][0] = 0;
    
            // for every row make that row 0 in matrix
            // for every col also make col 0 in matrix
            // for(int r=0; r<row.size(); r++){
            //     int max_length = max(m, n);
            //     for(int i=0; i<max_length; i++){
            //         if(i<n) matrix[row[r]][i] = 0;
            //         if(i<m) matrix[i][col[r]] = 0;
            //     }
            // }
            
        }
    };