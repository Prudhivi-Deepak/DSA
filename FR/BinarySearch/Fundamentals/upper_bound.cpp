class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        // int index = -1;
        int l = 0, r = nums.size()-1;

        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid] > x){
                // index = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return l;
    }
};