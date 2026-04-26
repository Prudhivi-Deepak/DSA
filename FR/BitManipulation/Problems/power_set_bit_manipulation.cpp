class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        // 1 2 3
        // 0 0 0 - 0
        // 0 0 1 - 1
        // 0 1 0 - 2
        // 0 1 1 - 3
        // 1 0 0 - 4
        // 1 0 1 - 5
        // 1 1 0 - 6
        // 1 1 1 - 7 -- 2**3-1

        vector<vector<int>> ans;

        for(int mask = 0; mask<(1<<nums.size()); mask++){
            vector<int> row;
            for(int i=0; i<nums.size(); i++){
                if(mask& (1<<i)){
                    row.push_back(nums[i]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};