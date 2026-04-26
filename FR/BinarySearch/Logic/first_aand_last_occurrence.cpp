class Solution{
public:
    int lowerBound(vector<int> &nums, int target){
        int l=0, r=nums.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] >= target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }

    int upperBound(vector<int> &nums, int target){
        int l=0, r=nums.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] > target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        // find lowerBound nums[i]>=target
        //     if check low index value == target set it else -1
        // find upperBound nums[i]> target
        //     if check upp-1 index value == target set it else -1

        vector<int> ans = {-1, -1};
        int low = lowerBound(nums, target), upp = upperBound(nums, target);
        cout << low << " : "<< upp-1 << endl;

        if(low>=0 && low<nums.size() && nums[low]==target) ans[0] = low;
        if(upp-1>=0 && upp-1 < nums.size() && nums[upp-1]==target) ans[1] = upp-1;

        return ans;
    }
};