class Solution {
public:
    void mergeArray(vector<int> &nums, int left, int mid, int right){

        long long int l1 = left, r1 = mid, l2 = mid+1, r2 = right;

        vector<int> ans;
        
        while(l1<=r1 && l2<=r2){

            if(nums[l1] <= nums[l2]){
                ans.push_back(nums[l1++]);
            }
            else{
                ans.push_back(nums[l2++]);
            }
        }

        while(l1<=r1){
            ans.push_back(nums[l1++]);
        }

        while(l2<=r2){
            ans.push_back(nums[l2++]);
        }

        for(int i=left; i<=right; i++){
            nums[i] = ans[i-left];
        }
    }

    long long int countPairs(vector<int> &nums, int left, int mid, int right){
        
        long long int l1 = left, r1 = mid, l2 = mid+1, r2 = right, count = 0;

        while(l1<=r1){
            while(l2<=r2 && nums[l1] > 2LL*nums[l2]) l2++;
            count += (l2-(mid+1)); // (l2-1)-(mid+1)-1
            l1++; 
        }
        return count;
    }

    long long int divideArray(vector<int> &nums, int left, int right){

        if(left >= right) return 0;
        long long int mid = left + (right-left)/2;
        int count = 0;

        count += divideArray(nums, left, mid);
        count += divideArray(nums, mid+1, right);
        count += countPairs(nums, left, mid, right);
        mergeArray(nums, left, mid, right);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return divideArray(nums, 0, nums.size()-1);
    }
};