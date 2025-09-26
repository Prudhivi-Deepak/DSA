#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> pre(n, 1);
        // , suf(n, 1);
        int LBS = 0;

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(arr[j]<arr[i] && pre[i]<pre[j]+1){
                    pre[i] = pre[j]+1;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            int left_LBS = pre[i];
            pre[i] = 1;
            for(int j=i+1; j<n; j++){
                if(arr[i]>arr[j] && pre[i]<pre[j]+1){
                    pre[i] = pre[j]+1;
                }
            }
            // LBS = max(LBS, suf[i]+pre[i]-1);
            LBS = max(LBS, left_LBS+pre[i]-1);
        }
        return LBS;
    }
};
