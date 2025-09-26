#include<bits/stdc++.h>

using namespace std;

int Solution(int n, int m, vector<vector<int>> &matrix ){
    vector<vector<int>> lTShapeSize(n, vector<int>(m, 0)), rTShapeSize(n, vector<int>(m, 0)), dTShapeSize(n, vector<int>(m, 0));

    for(int row=0; row<n; row++){
        int ones_count = 0;
        for(int col=0; col<m; col++){
            ones_count = matrix[row][col] ? ones_count+1 : 0 ;
            lTShapeSize[row][col] = ones_count;
        }
    }

    for(int row=0; row<n; row++){
        int ones_count = 0;
        for(int col=m-1; col>=0; col--){
            ones_count = matrix[row][col] ? ones_count+1 : 0 ;
            rTShapeSize[row][col] = ones_count;
        }
    }

    for(int col=0; col<m; col++){
        int ones_count = 0;
        for(int row=n-1; row>=0; row--){
            ones_count = matrix[row][col] ? ones_count+1 : 0 ;
            dTShapeSize[row][col] = ones_count;
        }
    }

    int maxTShapeSize = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int D = dTShapeSize[row][col];
            if (D % 2 != 0){
                int L = (D - 1) / 2 +1;
                if (lTShapeSize[row][col] >= L && rTShapeSize[row][col] >= L ) maxTShapeSize = max(maxTShapeSize, D);
            }
        }
    }

    return maxTShapeSize;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0},
        {1, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1}

    };

    cout << Solution(matrix.size(), matrix[0].size(), matrix) << endl;


    return 0;



}