class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // use left right top bottom pointers
        // left-> right top++
        // top -> bottom right--
        // if(top >= bottom)
        //     right -> left bottom--
        // if(left <= right)
        //     bottom -> top left++

        int top = 0, right = matrix[0].size()-1, left = 0, bottom = matrix.size()-1;
        vector<int> ans;

        while(left<=right && top<=bottom){

            for(int j=left; j<=right; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;

            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int j=right; j>=left; j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

        }
        return ans;       
    }
};