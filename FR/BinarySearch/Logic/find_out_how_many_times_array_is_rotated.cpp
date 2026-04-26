class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int l = 0, r = nums.size()-1, mid, mini = INT_MAX, mini_index;

        while(l<=r){
            mid = l+(r-l)/2;

            if(nums[l] <= nums[mid]){
                // left half sorted
                // search in right half
                // cout << l << " : " << mid << " mini : " << mini<< endl;
                if(nums[l] < mini){
                    mini = nums[l];
                    mini_index = l;
                }
                l = mid+1;
            }
            else{
                // cout << mid << " : " << r << " mini : " << mini<< endl;
                if(nums[mid] < mini){
                    mini = nums[mid];
                    mini_index = mid;
                }
                r =  mid-1;
            }
        }
        // cout << mini_index <<endl;
        // cout << nums[mini_index] << endl;
        // cout << nums.size() << endl;
        return mini_index;
    }
};