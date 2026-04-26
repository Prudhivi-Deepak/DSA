class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
      int n = arr.size();
      vector<int> prefixCount(n, 1);
      int lbs = 1;
      // suffixCount(n, 1);

      for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
          if(arr[j]<arr[i] && prefixCount[i]<prefixCount[j]+1){
            prefixCount[i]= 1+prefixCount[j];
          }
        }
      }

      for(int i=n-1; i>=0; i--){
        int currPrefixCount = prefixCount[i];
        prefixCount[i]=1;
        for(int j=n-1; j>i; j--){
          if(arr[j]<arr[i] && prefixCount[i]<prefixCount[j]+1){
            prefixCount[i]= 1+prefixCount[j];
          }
        }
         lbs = max(lbs, currPrefixCount+prefixCount[i]-1);
      }

      

      // for(int i=0; i<n; i++){
      //   lbs = max(lbs, prefixCount[i]+suffixCount[i]-1);
      // }

      return lbs;
    }
};
