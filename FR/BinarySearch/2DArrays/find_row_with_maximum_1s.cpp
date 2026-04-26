class Solution {
  public:   
  int rowIndex(vector <int> &row){
        int l = 0, r = row.size()-1, index = -1;

        while(l<=r){
            int mid = l+(r-l) /2;

            if(row[mid]==1){
                index = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return index;
  }

  int rowWithMax1s(vector < vector < int >> & mat) {
    
        // all rows are sorted in ascending order
        // for every row we have to find every index in row where 1s end
        // and take maximum ones index (if two index has same no. of ones--> take smaller index)
        int ans = -1, maxans = -1;
        for(int i=0; i<mat.size(); i++){
            int index = rowIndex(mat[i]);
            int siz = mat[i].size()-index;
            // cout << index << " : " << mat.size()-index << " : " <<  (siz > ans)<< endl;
            if(index!=-1 && (siz > maxans)){
                cout << index << endl;
                ans = i;
                maxans = siz;
            }
        }
        return ans;
  }
};