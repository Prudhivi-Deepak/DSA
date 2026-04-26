class Solution {
public:
    int findMin(vector<int> &arr)  {
      int l=0, r=arr.size()-1, ans = INT_MAX;

      while(l<=r){
        int mid = l+(r-l)/2;

        // if(mid>0 && mid<arr.size()-1 && arr[mid-1] > arr[mid] && arr[mid]<arr[mid+1]) return arr[mid];

        if(arr[l] <= arr[mid]){
            // sorted left half
            ans = min(ans, arr[l]);
            l = mid+1;
        }
        else{
            ans = min(ans, arr[mid]);
            r = mid-1;
        }
      }
      return ans;
    }
};