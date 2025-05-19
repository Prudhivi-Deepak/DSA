
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
    
            if(n < m) return findMedianSortedArrays(nums2, nums1);
    
            int left = 0, middle = (m+n+1)/2, mid1, mid2,l1,l2,r1,r2, right = m;
    
            while(left <= right){
                mid1 = left + (right - left)/2;
                mid2 = middle - mid1;
    
                l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
    
                if(mid1-1 >=0) l1 = nums1[mid1-1];
                if(mid2-1 >=0) l2 = nums2[mid2-1];
                if(mid1>=0 && mid1<nums1.size()) r1 = nums1[mid1];
                if(mid2>=0 && mid2<nums2.size()) r2 = nums2[mid2];
    
                //l1 should be less so go to left part
                if(l1 > r2) right = mid1-1;
                //r1 should be increased so go to right part
                else if(l2 > r1) left = mid1+1;
    
                else break;
            }
    
            if((nums1.size()+nums2.size())%2){
                return max(l1,l2);
            }
            else{
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
    };