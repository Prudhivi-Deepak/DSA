class Solution {
public:


    long long int mergeArray(vector<int> &nums, int left, int mid, int right){

        long long int l1 = left, r1 = mid, l2 = mid+1, r2 = right, count = 0;

        vector<int> ans;
        
        while(l1<=r1 && l2<=r2){

            if(nums[l1] <= nums[l2]){
                ans.push_back(nums[l1++]);
            }
            else{
                ans.push_back(nums[l2++]);
                count += (mid-l1+1);
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
        return count;
    }

    long long int divideArray(vector<int> &nums, int left, int right){

        if(left >= right) return 0;
        long long int mid = left + (right-left)/2;

        return divideArray(nums, left, mid)+divideArray(nums, mid+1, right)+mergeArray(nums, left, mid, right);
    }

    long long int numberOfInversions(vector<int> nums) {

        return divideArray(nums, 0, nums.size()-1);

        // for(auto i : nums){
        //     cout << i << " ";
        // }
        // cout << endl;

        // return 0;


    }
};