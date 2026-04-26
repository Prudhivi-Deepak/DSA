class Solution {
public:
    int search(vector<int> &nums, int k) {

        // 4, 5, 6, 7, 0, 1, 2 k = 0
        // we have to always search in sorted part okay
        // like 
        // if(l value <= mid) means left part is sorted
        //     if(l value <= k and k< mid value) means left part is sorted and we need k search there
        //     else means k is not in sorted left part--> search in right
        // else left is not sorted go to right sorted part and try there
        //     if(mid value <= k and k < right value) means k is in right sorted part go and search
        //     else k is not in right sorted part got to left part and search

        int l = 0, r = nums.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(nums[mid]==k) return mid;
            if(nums[l] <= nums[mid]){
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
        
        return -1;
       
    }
};