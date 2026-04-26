class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int targetSum) {

        // same way how we used 3 sum now do it for 4 sum as well
        // now we add one more layer where we fix 2 values and try to get other 2 values
        // target = -(v1+v2) --> to find other 2 values

        int n = nums.size();
        unordered_map<int,int> umap;
        set<vector<int>> ans;
        for(int k=0; k<n; k++){
            for(int i=k+1; i<n; i++){
                umap.clear();
                int target = targetSum-(nums[i]+nums[k]);
                for(int j=i+1; j<n; j++){
                    int need = target-nums[j];
                    if(umap.find(need)!=umap.end()){
                        // cout <<i << " : " << umap[need] << " : " << j << endl;
                        // ans.insert({nums[i], nums[umap[need]], nums[j]});
                        vector<int> temp = {nums[k], nums[i], nums[umap[need]], nums[j]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                    umap[nums[j]]=j;
                }
            }
        }
        return vector<vector<int>>{ans.begin(), ans.end()};

        
        
    }
};