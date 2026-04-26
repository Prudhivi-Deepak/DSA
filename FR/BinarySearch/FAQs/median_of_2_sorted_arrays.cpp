class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {

        int n = arr1.size(), m = arr2.size();

        if(n==1 && m==1) return (arr1[0]+arr2[0])/2.0;

        if(m < n) return median(arr2, arr1);

        int l = 0, r = n, total = (n+m+1)/2;

        while(l <= r){

            int mid = l+(r-l)/2;
            int mid2 = total-mid;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if(mid-1>=0 && mid-1<n) l1 = arr1[mid-1];
            if(mid2-1>=0 && mid2-1<m) l2 = arr2[mid2-1];

            if(mid>=0 && mid<n) r1 = arr1[mid];
            if(mid2>=0 && mid2<m) r2 = arr2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n+m)%2){
                    return max(l1, l2);
                }
                return ((double)max(l1, l2)+min(r1,r2))/2;
            }
            else if(l1 > r2){
                r = mid-1;
            }
            else l = mid+1;
        }
        return -1;        
    }
};