class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // we need to store result in new vector
        // we need 2 pointers a pos, neg pointers
        // each time i will find a positive one and neg one
        // push them to teh new array simple

        vector<int> ans;

        int pos = 0, neg = 0;

        while(pos< nums.size() && neg< nums.size()){

            while(pos< nums.size() && nums[pos]<0) pos++;
            while(neg< nums.size() && nums[neg]>0) neg++;

            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);

            pos++;
            neg++;
        }
        return ans;        
    }
};