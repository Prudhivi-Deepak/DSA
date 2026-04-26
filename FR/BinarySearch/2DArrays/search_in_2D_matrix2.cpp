class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){

        // [1, 4, 7, 11, 15], 
        // [2, 5, 8, 12, 19], 
        // [3, 6, 9, 16, 22], 
        // [10, 13, 14, 17, 24], 
        // [18, 21, 23, 26, 30]

        // m,n
        // start from right top 0, n-1

        // if target < currValue then move j--;
        // else i++;

        int m = matrix.size(), n = matrix[0].size(), i = 0, j = n-1;

        while(i<m && j>=0){
            if(target == matrix[i][j]) return true;
            else if(target < matrix[i][j]) j--;
            else i++;
        }
        return false;      
    }
};