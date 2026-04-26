class Solution{
public:

    int upperBound(vector<int> &row, int target){

        int l = 0, r = row.size()-1;
        // index  = -1;

        while(l<=r){

            int mid = l+(r-l)/2;

            if(row[mid] > target){
                // index = mid;
                r = mid-1;
            }
            else l =mid+1;
        }
        return l;
    }

    int findMedian(vector<vector<int>>&matrix) {

        // row wise sorted --> to find median value we know we need a value from whole matrix
        // where the count of elements < median should be equal to count of elements > median
        // we know that median index = (n*m+1)/2 right = required

        // so we need that many count (elements) == required return that index value

        // so for every possible median value check the matrix for the count --> median value range from 0 to 1e9
        // and return the smallest index value that is satisfying

        int m = matrix.size(), n = matrix[0].size(), l = INT_MAX, r = 1e9, requiredCount = (n*m+1)/2, value = -1;

        cout << requiredCount << endl;

        for(int i=0; i<matrix.size(); i++){
            l = min(l, matrix[i][0]);
            r = max(r, matrix[i][n-1]);
       }

        while(l<=r){
            int mid = l+(r-l)/2;

            int count = 0;

            for(int i=0; i<matrix.size(); i++){
                count += upperBound(matrix[i], mid);
            }

            // cout << " count : " << count << endl;

            // if(count == requiredCount) return mid;
            // else 
            // some kind of lower bound
            if(count >= requiredCount){
                r = mid-1;
            }
            else l = mid+1;
        }
        return l;
    }
};