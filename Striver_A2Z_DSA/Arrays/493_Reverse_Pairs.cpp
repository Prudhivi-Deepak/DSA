#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void MergeArray(int left, int mid, int right, vector<int> &nums){
            int i=left, j = mid+1;
            // length=0;
            vector<int> arr3;
    
            while(i<=mid && j<=right){
                if(nums[i] <= nums[j]){
                    arr3.push_back(nums[i]);i++;
                }
                else{
                    // if(nums[i] > 2*nums[j]){ 
                    //     cout << nums[i] << " : " << 2*nums[j] << endl;
                    //     length += (mid-i+1);
                    // }
                    arr3.push_back(nums[j]);j++;
                }
            }
    
            while(i<=mid){
                 arr3.push_back(nums[i]);i++;
            }
    
            while(j<=right){
                arr3.push_back(nums[j]);j++;
            }
    
            for(int i=left; i<=right; i++){
                nums[i] = arr3[i-left];
            }
    
            // return length;
    
        }
    
        int CountPairs(int left, int mid, int right, vector<int> &nums){
            int i=left, j = mid+1, length = 0;
    
            while(i<=mid){
                while(j <= right && nums[i] > (long long)nums[j]*2) j++;
                length += j-mid-1;//((j-1)-(mid+1)+1)
                i++;
            }
            return length;
        }
    
        int DivideArray(int left, int right, vector<int> &nums){
            int cnt = 0;
            if(left>=right) return cnt;
            int mid = left+(right-left)/2;
            cnt += DivideArray(left, mid, nums);
            cnt += DivideArray(mid+1, right, nums) ;
            cnt += CountPairs(left, mid, right, nums);
            MergeArray(left, mid, right, nums);
            return cnt;
        }
        int reversePairs(vector<int>& nums) {
            return DivideArray(0, nums.size()-1, nums);
        }
    };