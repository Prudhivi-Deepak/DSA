class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        // 1 2 5 3 1 2
        // iterate from right to left --> maintain the max element and store it when changes in an array
        // reverse it and return it

        int n = nums.size()-1, leader = nums[n], i=n-1;

        vector<int> ans;
        ans.push_back(leader);

        while(i>=0){
            if(nums[i] > leader){
                // cout << nums[i] << " > " << leader << endl;
                leader = nums[i];
                ans.push_back(nums[i]);
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};