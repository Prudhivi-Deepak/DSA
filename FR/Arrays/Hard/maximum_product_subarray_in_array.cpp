class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prefixPro=0, suffixPro=0, maxPro = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            if(prefixPro==0) prefixPro = 1;
            if(suffixPro==0) suffixPro = 1;

            prefixPro *= nums[i];
            suffixPro *= nums[nums.size()-1-i];

            maxPro = max({maxPro, prefixPro, suffixPro});
        }
        return maxPro;
    }
};