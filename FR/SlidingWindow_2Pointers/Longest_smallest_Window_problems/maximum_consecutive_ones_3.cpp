class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here

        int l = 0, r = 0, n = nums.size(), maxlength = 0, zerocnt = 0;

        while(r<n){
            if(nums[r]==0) zerocnt++;

            if(zerocnt>k){
                while(zerocnt>k){
                    if(nums[l]==0) zerocnt--;
                    l++;
                }
            }
            // valid zero's cnt and take maxlength now
            maxlength = max(maxlength, r-l+1);
            r++;
        }
        return maxlength;       
    }
};