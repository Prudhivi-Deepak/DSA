class Solution {
public:
    int numberOfLIS(vector<int> nums) {
        int n = nums.size();
        vector<int> count(n, 0), ways(n, 1);
        int lis_count = 0, max_lis = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i] && count[i] < count[j]+1){
                    count[i] = count[j]+1;
                    ways[i] = ways[j];
                }
                else if(count[i] == count[j]+1){
                    ways[i] += ways[j];
                }
            }
            max_lis = max(max_lis, count[i]);
            // cout << ways[i] << endl;
        }

        for(int i=0; i<n; i++){
            if(max_lis == count[i]){
                lis_count += ways[i];
            }
        }

        return lis_count;

    }
};
