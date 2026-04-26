class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        // 0 1 2   k = 2
        // 1 1 1

        // no. of ways = 
        // 0 = 0
        // 1 = 0
        // 2 = 1

        // 0 = -1 (1 ways)
        // 1 =  0 (1-2 = -1) ?? no (1 ways)
        // 2 =  1 (2-2 = 0) yes (1- -1 = 2) (2 way)
        // 3 =  2 (3-2 = 1) yes (3-0 = 3) (2 ways)

        unordered_map<int,int> umap;
        umap[0] = 1;
        int sum = 0, ways = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            ways += umap[sum-k];
            umap[sum]++;
        }
        return ways;
    }
};