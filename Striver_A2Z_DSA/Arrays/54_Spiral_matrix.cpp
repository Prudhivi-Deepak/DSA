#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int top = 0, left = 0, right = matrix[0].size()-1, bottom = matrix.size()-1, n = matrix[0].size();
    
            // print this loops until n/2 for even and n/2 + 1 for odd
            vector<int> result;
            // while((left%2==0 && left< n/2) || (left%2 && left< n/2+1)){
            while(top <= bottom && left <= right){
                //print top : left to right
                for(int i=left; i<=right; i++){
                    // cout << matrix[top][i] << " ";
                    result.push_back(matrix[top][i]);
                }
                top++;
    
                //now print right : top to bottom
                for(int i=top; i<=bottom; i++){
                    // cout << matrix[i][right] << " ";
                    result.push_back(matrix[i][right]);
                }
                right--;
    
                if(top <= bottom){
                    //now print bottom : right to left
                    for(int i=right; i>=left; i--){
                        // cout << matrix[bottom][i] << " ";
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
    
    
                if(left <= right){
                    //Now print left: bottom to top
                    for(int i=bottom; i>=top; i--){
                        // cout << matrix[i][left] << " ";
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
    
            return result;
        }
    };