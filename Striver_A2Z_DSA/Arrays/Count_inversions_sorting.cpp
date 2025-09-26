#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long int MergeArray(long long int left, long long int mid, long long int right, vector<int> &nums){
            vector<int> arr3;
            // long long int mid = left+(right-left)/2;
            long long int i=left, j=mid+1, count = 0;
    
            while(i<=mid && j <= right){
                if(nums[i]<=nums[j]){
                    arr3.push_back(nums[i++]);
                }
                else{
                    arr3.push_back(nums[j++]);count+=(mid-i+1);
                }
            }
    
            while(i<=mid){
                arr3.push_back(nums[i++]);
                // count+=(mid-left+1);
            }
    
            while(j<=right){
                arr3.push_back(nums[j++]);
            }
    
            for(int i=left; i<=right; i++){
                nums[i] = arr3[i-left];
            }
    
            return count;
    
        }
    
        long long int DivideArray(long long int left, long long int right, vector<int> &nums){
            if(left >= right) return 0;
            long long int mid = left+(right-left)/2;
            return DivideArray(left, mid, nums) + DivideArray(mid+1, right, nums) + MergeArray(left, mid, right, nums);
        }
    
       long long int numberOfInversions(vector<int> nums) {
            return DivideArray(0, nums.size()-1, nums);
        }
    };