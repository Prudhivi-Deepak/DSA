class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int l = 2, r = n-3;

        // even odd single numebr odd even

        while(l<=r){
            int mid = l+(r-l)/2;

            if(mid%2){
                // even odd
                if(nums[mid-1]==nums[mid]){
                    // go to right
                    l = mid+1;                                        
                }
                else if(nums[mid]==nums[mid+1]){
                    // go to left
                    r = mid-1;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(nums[mid] == nums[mid+1]){
                    // go to right
                    l = mid+1;  
                }
                else if(nums[mid-1] == nums[mid]){
                    // go to left
                    r = mid-1;
                }
                else return nums[mid];
            }
        }
        return -1;
    }
};