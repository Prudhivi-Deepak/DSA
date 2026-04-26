class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size(), last_index = 0;
        sort(nums.begin(), nums.end());

        vector<int> count(n+1, 0), parent(n+1, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && count[i] < count[j]+1){
                    count[i] = count[j]+1;
                    parent[i] = j;
                }
            }

            if(count[i] > count[last_index]){
                last_index = i;
            }
        }

        vector<int> ans;

        while(last_index != parent[last_index]){
            ans.push_back(nums[last_index]);
            last_index = parent[last_index];
        }
        ans.push_back(nums[last_index]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
