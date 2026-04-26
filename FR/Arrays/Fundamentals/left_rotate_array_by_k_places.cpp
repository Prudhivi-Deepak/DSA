class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {

        // offcourse k=k%n
        // then we reverse from 0 to k then k+1 to end
        // then whole array 
        // simply way to rotate that's it
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};