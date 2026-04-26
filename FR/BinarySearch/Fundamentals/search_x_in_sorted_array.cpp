class Solution{
public:
    int search(vector<int> &nums, int target){
        // sorted array
        // so binary search works fine
        // while l<=r
        //     l = 0, r = nums.size()-1
        //     mid = r-(r-l)/2;
        //     if found return index
        // return -1

        int l=0, r = nums.size()-1;

        while(l<=r){

            int mid = r-(r-l)/2;

            if(target == nums[mid]) return mid;
            else if(target < nums[mid]){
                r = mid-1;
            }
            else l = mid+1;
        }
        return -1;
    }
};