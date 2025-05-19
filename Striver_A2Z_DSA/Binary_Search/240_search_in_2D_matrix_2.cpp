
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int i = matrix[0].size()-1, j = 0;
            while(i >= 0 && j < matrix.size()){
                if(matrix[j][i] == target) return true;
                else if(target < matrix[j][i]) i--;
                else j++;
            }
            return false;
        }
    };