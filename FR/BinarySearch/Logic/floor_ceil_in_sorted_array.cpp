class Solution {
public:
    int lowerBound(vector<int> &nums, int x){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid]==x) return mid+1;
            if(nums[mid] >= x) r = mid-1;
            else l = mid+1;
        }
        return l;
    }

    int upperBound(vector<int> &nums, int x){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = r-(r-l)/2;
            if(nums[mid]==x) return mid;
            if(nums[mid] > x) r = mid-1;
            else l = mid+1;
        }
        return l;
    }

    vector<int> getFloorAndCeil(vector<int> &nums, int x) {

        // floor value means --> lesser value than curr x
        //     means find a value in nums[i] >= x then we can simply do index-1 = lowerBound-1
        
        // ceil value means --> find a value greater than x
        //     means find a value in nums[i] > x then we can simply return upperBound
        // cout << lowerBound(nums, x) << " : "<< upperBound(nums, x) << endl;
        int low = lowerBound(nums, x);
        int  upp = upperBound(nums, x);
        return {(low==0 ? -1 : nums[low-1]),(upp>=nums.size() ? -1 : nums[upp])};

    }
};