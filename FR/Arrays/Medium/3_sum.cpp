class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // iterate from i=0 to n --> 
        // for every i fix the value and try to find other 2 values from i+1 to n --> using umap
        int n = nums.size();
        unordered_map<int,int> umap;
        set<vector<int>> ans;
        for(int i=0; i<n; i++){
            umap.clear();
            int target = -nums[i];
            for(int j=i+1; j<n; j++){
                int need = target-nums[j];
                if(umap.find(need)!=umap.end()){
                    // cout <<i << " : " << umap[need] << " : " << j << endl;
                    // ans.insert({nums[i], nums[umap[need]], nums[j]});
                    vector<int> temp = {nums[i], nums[umap[need]], nums[j]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                umap[nums[j]]=j;
            }
        }
        return vector<vector<int>>{ans.begin(), ans.end()};
    }
};