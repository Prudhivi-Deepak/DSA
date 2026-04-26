class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;

        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid]>=target){
                r = mid-1;
            }
            else l = mid+1;
        }
        return l;
    }

    int searchInsert(vector<int> &nums, int target)  {
       
    //    we need to find where the target element must have inserted
    //    so find a smallest index where the nums[i] >= target
    //    so that index == our required index the actual target should have been inserted
    //    so find lower bound and return
        return lowerBound(nums, target);
    }
};