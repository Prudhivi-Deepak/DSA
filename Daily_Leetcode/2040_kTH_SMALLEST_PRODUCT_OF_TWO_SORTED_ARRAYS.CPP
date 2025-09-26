#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long upperBound(vector<int> &nums, long long k){
        long long l=0, r = nums.size()-1;
        long long index = 0;

        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid]<=k){
                index = mid; l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }

    long long lowerBound(vector<int> &nums, long long k){
        long long l=0, r = nums.size()-1;
        long long index = 0;

        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid]<k){
                index = mid; l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }

    long long f(vector<int> &nums1, vector<int> &nums2, long long mid){
        long long count = 0;

        int n1 = nums1.size(), n2 = nums2.size();

        for(int i=0; i<n1; i++){

            int x = nums1[i];
            if(x > 0){
                long long target = floor((double)mid/x);
                count += upperBound(nums2, target);
            }
            else if(x<0){
                long long target = ceil((double)mid/x);
                count += n2 - lowerBound(nums2, target);
            }
            else if(mid>=0){
                count+=n2;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // BS = -1e10, 1e10
        // find smallest number x such that there are atleast k products <= x

        // counting no.of products <= mid
            // do this by iterating through each nums1[i] and using BS inside num2

        // case 1: nums1[i] > 0
            // x>0  => (product  = mid2 * x) ==> how many numbers are <= mid/x =>custom upper function


        // case 2: nums1[i] < 0
            // x<0  => (product  = -ve() mid2 * x) ==> how many numbers are >= -ve() ceil(mid/x) =>custom lower function returns how many are < target
            // subtract it from m to get total no. of elements >= target
        
        // case 3: nums1[i] == 0
            // product is always 0
            // if mid >= 0 then all 0s satisfy te condition ==> count += m
            // product(0) > mid ==> no products added

        // BS ==> [-1e10, 1e10]
        // for each mid 
            // count how many products <= mid
                // if count >= k then mid might be answer - search left
                // else search right
        // when loop ends i points to kth smallest product

        // custome upper and lower functions
            // upper(nums, k) => count how many are numbers <= k
            // lower(nums, k) => count how many numbers < k


        long long l = -1e10, r = 1e10, ans = 0;
        while(l<=r){
            long long mid = r-(r-l)/2;
            long long c = f(nums1, nums2, mid);

            if(c>=k){
                ans = mid; r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
        // + - = -
        // - + = -
        // + + = +
        // - - = +
    }
};