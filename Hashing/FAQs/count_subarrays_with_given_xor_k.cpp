class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int,int> umap;

        umap[0] = 1;
        int xor1 = 0, ways = 0;

        for(int i=0; i<nums.size(); i++){
            xor1 ^= nums[i];
            ways += umap[xor1^k];
            umap[xor1]++;
        }
        return ways;
    }
};