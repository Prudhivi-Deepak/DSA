class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        // int n = matrix.size(), m = matrix[0].size();
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=i; j++){
        //         int new_row = j;
        //         int new_col = (m-1)-i;
        //         matrix[new_row][new_col] = matrix[i][j];
        //     }
        // }     
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};