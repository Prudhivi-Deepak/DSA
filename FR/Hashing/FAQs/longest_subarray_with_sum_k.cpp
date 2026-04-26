class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<int,int> umap;
        umap[0] = -1;
        int sum = 0, maxLen = 0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            // cout << sum << endl;
            if(umap.find(sum-k) != umap.end()){
                // cout << i << " - " << umap[sum-k] << " sum : " << sum << endl;
                maxLen = max(maxLen, i-umap[sum-k]);
            }
            if(umap.find(sum)==umap.end()) umap[sum] = i;
        }
        return maxLen;
    }
};
