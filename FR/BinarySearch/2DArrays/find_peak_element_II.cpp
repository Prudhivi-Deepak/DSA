class Solution {
public:
    // int findPeak(vector<int> &row){

    //     if(row.size()==1) return 0;

    //     int l = 0, n = row.size()-1;
    //     if(row[0] > row[1]) return 0;
    //     if(row[n-1] < row[n]) return n;
    //     l = 1;
    //     int r = n-1;

    //     while(l<=r){
    //         int mid = l+(r-l)/2;
    //         if(row[mid-1] < row[mid] && row[mid] > row[mid+1]) return mid;
    //         else if(row[mid-1] < row[mid]) l = mid+1;
    //         else r = mid-1;
    //     }
    //     return -1;        
    // }

    int findPeakinCol(vector<vector<int>>& mat, int col){

        int maxi = mat[0][col], maxi_index = 0;

        for(int i=1; i<mat.size(); i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                maxi_index = i;
            }
        }
        return maxi_index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        // we have to find peak value in each row and try for col validity
        // BS for each row
        // return any one peak number
        // otherwise 0

        // for(int i=0; i<mat.size(); i++){
        //     int index = findPeak(mat[i]);
        //     cout << index << endl;
        //     if(index!=-1){
        //         bool up = (i==0) ||  mat[i-1][index]<mat[i][index];
        //         bool down = (i==mat.size()-1 || mat[i][index] > mat[i+1][index]);
        //         if(up && down) return vector<int>{i, index};
        //     }
        // }

        int l = 0, r = mat[0].size()-1;

        while(l<=r){

            int mid = l+(r-l)/2;

            int index = findPeakinCol(mat, mid);

            bool left = ((mid==0) || (mat[index][mid-1] < mat[index][mid]));
            bool right = ((mid==mat[0].size()-1) || (mat[index][mid] > mat[index][mid+1]));

            if(left && right) return {index, mid};
            else if(left && !right) l = mid+1;
            else r = mid-1;
        }

        return {-1, -1};
        
    }
};