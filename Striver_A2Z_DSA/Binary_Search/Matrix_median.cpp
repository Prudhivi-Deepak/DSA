#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        //return the index at which the number is greater than x
        // logn
        int upperBound(vector<int> arr, int x){
            int left = 0, right = arr.size()-1, mid;
            while(left <= right){
                mid = left+(right-left)/2;
                if(arr[mid] <= x) left = mid+1;
                else right = mid-1; 
            }
            return left;
        }
        //m*logn
        bool FindCountofNumbersLessMiddleAtIndex(vector<vector<int>> &matrix, int middle, int mid){
            int count = 0;
            for(int i=0; i<matrix.size(); i++){
                count += upperBound(matrix[i], mid);
            }
            return count <= middle;
        }
    
    
        int findMedian(vector<vector<int>>&matrix) {
           int m = matrix.size(), n = matrix[0].size(), mid, middle = (m*n)/2;
           int left = matrix[0][0], right = matrix[0][n-1];
    
            //O(m)
           for(int i=1; i<m; i++){
                left = min(left, matrix[i][0]);
                right = max(right, matrix[i][n-1]);
           }
    
            //O(m) + logm*m*log(max-min)
           while(left <= right){
                mid = left+(right-left)/2;
    
                if(FindCountofNumbersLessMiddleAtIndex(matrix, middle, mid)) left = mid+1;
                else right = mid-1;
           }
    
           return left;
        }
    };