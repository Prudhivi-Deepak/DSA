class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here

        // maintain 2 varibles maxi, secondMaxi--> both initialize to INT_MIN or maxi initialize to nums[0], secondMaxi to INT_MIN
        // now iterate array from i=1 to nums.size()-1
        // now if nums[i] > maxi then secondMaxi = maxi and maxi = nums[i]
        // else if secondMaxi < nums[i] && nums[i]!=maxi then secondMaxi = nums[i]

        int maxi = nums[0], secondMaxi = INT_MIN;

        for(int i=1; i<nums.size(); i++){

            if(nums[i] > maxi){
                secondMaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secondMaxi && nums[i]!=maxi){
                secondMaxi = nums[i];
            }
        }
        if(secondMaxi == INT_MIN) return -1;
        return secondMaxi;     
    }
};