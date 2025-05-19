#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int FindMaxIndex(vector<vector<int>> &mat, int col_mid){
            int max_row_index = 0, max_ele = mat[0][col_mid];
    
            for(int i=1; i<mat.size(); i++){
                if(max_ele <  mat[i][col_mid]){
                    max_ele = mat[i][col_mid];
                    max_row_index = i;
                }
            }
    
            return max_row_index;
        }
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int m = mat.size(), n = mat[0].size();
            int left = 0, right = n-1, mid;
    
            while(left<=right){
                mid = left+(right-left)/2;
    
                int max_row_index = FindMaxIndex(mat, mid);
    
                bool isLeft = mid-1<0 ? 1 : mat[max_row_index][mid-1] < mat[max_row_index][mid];
                bool isRight = mid+1>=n ? 1 : mat[max_row_index][mid] > mat[max_row_index][mid+1];
    
                if(isLeft && isRight) return vector<int>{max_row_index, mid};
                else if(isLeft && !isRight) left = mid+1;
                else right = mid-1;
                
            }
    
            return vector<int>{-1,-1};
        }
    };