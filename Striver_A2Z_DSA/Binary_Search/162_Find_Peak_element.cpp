#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& arr) {
            int left =1, n=arr.size(), right = n-2, mid;
    
            if(n==1 || arr[0] > arr[1]) return 0;
    
            if(arr[n-2] < arr[n-1]) return n-1;
    
            while(left <= right){
                mid = left + (right-left)/2;
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                    return mid;
                }
                else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) left = mid+1;
                else right = mid-1;
            }
    
            return -1;
        }
    };