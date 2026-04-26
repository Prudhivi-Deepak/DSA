class Solution {
public:
    int f(int i, int prev_index, vector<int>& nums, vector<vector<int>> &dp){

        if(i==0){
            // if(prev_index==nums.size()) return 1;
            // if( prev_index < nums.size() && nums[prev_index] > nums[0]) return 1;
            if(prev_index == nums.size() || nums[prev_index] > nums[0]) return 1;
            return 0;
        }

        if(dp[i][prev_index]!=-1) return dp[i][prev_index];
        
        int notTake = f(i-1, prev_index, nums, dp);

        int Take = 0;
        if(prev_index==nums.size() || nums[prev_index] > nums[i]) Take = 1 + f(i-1, i, nums, dp);

        return dp[i][prev_index] = max(notTake, Take);
    }

    int lower_bound_index(vector<int> &nums, int target){
        // we have to find the smallest index with value
        // that is greater or equal to the target

        int left=0, right=nums.size()-1, index = -1;
        while(left<=right){
            int mid = right - (right-left)/2;

            // cout << mid << endl;

            if(nums[mid] >= target){
                index = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return index;

    }

    int LIS(vector<int>& nums) {

        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){

            int lb_index = lower_bound_index(lis, nums[i]);
            // // cout << lb_index << " : " << lis.size() << endl;

            if(lb_index != -1 && lb_index<lis.size()){
                lis[lb_index] = nums[i];
            }
            else{
                lis.push_back(nums[i]);
            }
        }
        return lis.size();
    }

    int LISDP(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        vector<int> prev(n+1, 0), curr(n+1, 0);

        // i goes from n-2 to 0
        // base case : for any prev index  nums[prev_index] > nums[0] 

        for(int prev_index=0; prev_index<=n; prev_index++){
            // if(nums[prev_index] > nums[0]) dp[0][prev_index] = 1;
            if(prev_index==nums.size() || nums[prev_index] > nums[0]) prev[prev_index] += 1;
        }

        for(int i=1; i<n; i++){
            for(int prev_index=0; prev_index<=n; prev_index++){
                // int notTake = dp[i-1][prev_index];
                int notTake = prev[prev_index];
                int Take = 0;
                if(prev_index==nums.size() || nums[prev_index] > nums[i]) 
                    // Take = 1 + dp[i-1][i];
                    Take = 1 + prev[i];

                // dp[i][prev_index] = max(notTake, Take);
                curr[prev_index] = max(notTake, Take);
            }
            prev = curr;
        }
        // return dp[n-2][n-1]+1;
        return prev[n];
        // return f(n-1, n, nums, dp) ;
    }    
};