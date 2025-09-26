#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<int> pascalRow(numRows, 0), prev_pascalRow(numRows, 0);
            vector<vector<int>> fullPascalTriangle{{1}}; 
            pascalRow[0] = 1; prev_pascalRow[0] = 1;
    
            for(int row=1; row<numRows; row++){
                pascalRow = {1};
                for(int i=1; i<=row; i++){
                    if(i==fullPascalTriangle[row-1].size()) pascalRow.push_back(1);
                    else pascalRow.push_back(fullPascalTriangle[row-1][i]+fullPascalTriangle[row-1][i-1]);
                    // pascalRow[i] = prev_pascalRow[i]+prev_pascalRow[i-1];
                }
                // prev_pascalRow = pascalRow;
                fullPascalTriangle.push_back(pascalRow);
            }
    
            return fullPascalTriangle;
        }
    };