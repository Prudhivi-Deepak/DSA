class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {

        int l = 0, r = nums.size()-1;

        while(l<=r){
            // cout << l << " : " << r << endl;
            int mid = l+(r-l)/2;
            // cout << mid << endl;

            if(nums[mid]==k) return true;
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++; r--;
            }
            else if(nums[l] <= nums[mid]){
                // left sorted psrt
                if(nums[l] <=k && k < nums[mid]){
                    // search inleft part
                    r = mid-1;
                }
                else l = mid+1;
            }
            else{
                // right part is sorted
                if(nums[mid] < k && k <= nums[r]){
                    // serach is right sorted part
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        
        return false;
      
    }
};