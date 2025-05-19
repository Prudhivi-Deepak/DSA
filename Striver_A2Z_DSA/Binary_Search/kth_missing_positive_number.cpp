#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int left = 0, right = arr.size()-1, mid;
    
            while(left<=right){
                mid = left + (right-left)/2;
                if(arr[mid]-(mid+1) < k) left = mid+1;
                else right = mid-1;
            }
            if(right<0) return k;
            cout << right << endl;
    
            return k+right+1;
            // return arr[right] + (k-(arr[right]-(right+1))); // add rem numbers after we do k-mid to the mid val 
            // arr[right] + k-arr[right]+(right+1)
    
        }
    };